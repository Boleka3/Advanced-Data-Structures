#include <bits/stdc++.h>
using namespace std;

////////////////////////////////////////////////////////////
// Skip List Node Definition
////////////////////////////////////////////////////////////
struct SkipNode {
    int playerID;
    int score;
    vector<SkipNode*> forward; // forward pointers for each level

    SkipNode(int pid, int sc, int level)
            : playerID(pid), score(sc), forward(level, nullptr) {}
};

////////////////////////////////////////////////////////////
// Skip List Definition
////////////////////////////////////////////////////////////
class SkipList {
private:
    // Probability and maximum level parameters
    float probability;
    int maxLevel;
    int currentLevel;

    SkipNode* head; // dummy head at highest level

    // Generate random level for insertion
    int randomLevel() {
        int lvl = 1;
        while (((float)rand() / RAND_MAX) < probability && lvl < maxLevel) {
            lvl++;
        }
        return lvl;
    }

public:
    SkipList(int maxL = 16, float p = 0.5f) : maxLevel(maxL), probability(p) {
        currentLevel = 1;
        head = new SkipNode(-1, INT_MAX, maxLevel);
        // We use INT_MAX score for head as a sentinel (highest possible)
    }

    ~SkipList() {
        SkipNode* node = head;
        while (node) {
            SkipNode* next = node->forward[0];
            delete node;
            node = next;
        }
    }

    // Insert node by descending score
    void insertNode(int playerID, int score) {
        vector<SkipNode*> update(maxLevel, nullptr);
        SkipNode* current = head;

        // Move from top level down
        for (int i = currentLevel - 1; i >= 0; i--) {
            // Since we are sorted by descending order, we move forward
            // while next node has higher or equal score
            while (current->forward[i] && current->forward[i]->score >= score) {
                current = current->forward[i];
            }
            update[i] = current;
        }

        // current is at the position where we should insert our new node
        // Insert after 'current' at level 0
        int lvl = randomLevel();
        if (lvl > currentLevel) {
            for (int i = currentLevel; i < lvl; i++) {
                update[i] = head;
            }
            currentLevel = lvl;
        }

        SkipNode* newNode = new SkipNode(playerID, score, lvl);
        for (int i = 0; i < lvl; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }

    // Delete node by exact score & playerID
    bool deleteNode(int playerID, int score) {
        vector<SkipNode*> update(maxLevel, nullptr);
        SkipNode* current = head;

        // Find the node to be deleted
        for (int i = currentLevel - 1; i >= 0; i--) {
            while (current->forward[i] &&
                   (current->forward[i]->score > score ||
                    (current->forward[i]->score == score && current->forward[i]->playerID > playerID))) {
                current = current->forward[i];
            }
            update[i] = current;
        }

        SkipNode* target = current->forward[0];
        if (target && target->score == score && target->playerID == playerID) {
            // Adjust pointers
            for (int i = 0; i < currentLevel; i++) {
                if (update[i]->forward[i] != target) break;
                update[i]->forward[i] = target->forward[i];
            }
            delete target;
            // Adjust currentLevel if needed
            while (currentLevel > 1 && head->forward[currentLevel - 1] == nullptr) {
                currentLevel--;
            }
            return true;
        }
        return false;
    }

    // Search by score (and playerID if needed), returns pointer to node
    SkipNode* searchNode(int playerID, int score) {
        SkipNode* current = head;
        for (int i = currentLevel - 1; i >= 0; i--) {
            while (current->forward[i] &&
                   (current->forward[i]->score > score ||
                    (current->forward[i]->score == score && current->forward[i]->playerID > playerID))) {
                current = current->forward[i];
            }
        }
        current = current->forward[0];
        if (current && current->score == score && current->playerID == playerID) {
            return current;
        }
        return nullptr;
    }

    // Retrieve top N nodes (by highest score)
    vector<pair<int,int>> getTopN(int N) {
        vector<pair<int,int>> result;
        SkipNode* current = head->forward[0]; // first actual node
        int count = 0;
        while (current && count < N) {
            result.push_back({current->playerID, current->score});
            current = current->forward[0];
            count++;
        }
        return result;
    }
};


////////////////////////////////////////////////////////////
// Leaderboard / Game Management
////////////////////////////////////////////////////////////

class Leaderboard {
private:
    SkipList skiplist;
    unordered_map<int, pair<int,int>> playerInfo;
    // Maps playerID -> (score, lastKnownScore)
    // Alternatively, we can store playerID -> score and rely on a separate structure for nodes.

    // To efficiently update scores (remove/insert), we need playerID -> current score mapping
    // Because to remove a player from skiplist, we must know their current score and ID.

public:
    Leaderboard() {}

    // Player joins with initial score = 0 (or some default)
    void playerJoin(int playerID, int initialScore = 0) {
        // Insert into skiplist
        skiplist.insertNode(playerID, initialScore);
        // Store in map
        playerInfo[playerID] = {initialScore, initialScore};
    }

    // Player leaves: remove from skiplist and map
    void playerLeave(int playerID) {
        if (playerInfo.find(playerID) != playerInfo.end()) {
            int score = playerInfo[playerID].first;
            skiplist.deleteNode(playerID, score);
            playerInfo.erase(playerID);
        }
    }

    // Update a player's score
    void updateScore(int playerID, int newScore) {
        // find current score
        if (playerInfo.find(playerID) == playerInfo.end()) {
            // Player not found, they might need to join first
            return;
        }
        int oldScore = playerInfo[playerID].first;
        // Remove old entry
        skiplist.deleteNode(playerID, oldScore);
        // Insert new entry
        skiplist.insertNode(playerID, newScore);
        // Update map
        playerInfo[playerID].first = newScore;
    }

    // Retrieve top N players
    vector<pair<int,int>> getTopN(int N) {
        return skiplist.getTopN(N);
    }

    // Get a player's current score
    int getPlayerScore(int playerID) {
        if (playerInfo.find(playerID) != playerInfo.end()) {
            return playerInfo[playerID].first;
        }
        // If not found
        return -1;
    }
};


////////////////////////////////////////////////////////////
// Example Usage (main)
////////////////////////////////////////////////////////////

int main() {
    srand((unsigned)time(NULL));

    Leaderboard lb;
    // Players join
    lb.playerJoin(1001, 50);
    lb.playerJoin(1002, 75);
    lb.playerJoin(1003, 20);

    cout << "Top 3 players:\n";
    for (auto &p : lb.getTopN(3)) {
        cout << "PlayerID: " << p.first << ", Score: " << p.second << "\n";
    }

    // Update scores
    lb.updateScore(1003, 80); // Player 1003 jumps to top
    cout << "\nAfter updating player 1003's score to 80:\n";
    for (auto &p : lb.getTopN(3)) {
        cout << "PlayerID: " << p.first << ", Score: " << p.second << "\n";
    }

    // Add a new player
    lb.playerJoin(1004, 90);
    cout << "\nAfter player 1004 joins with score 90:\n";
    for (auto &p : lb.getTopN(3)) {
        cout << "PlayerID: " << p.first << ", Score: " << p.second << "\n";
    }

    // Player leaves
    lb.playerLeave(1002);
    cout << "\nAfter player 1002 leaves:\n";
    for (auto &p : lb.getTopN(3)) {
        cout << "PlayerID: " << p.first << ", Score: " << p.second << "\n";
    }

    // Check a player's score
    cout << "\nPlayer 1001's score: " << lb.getPlayerScore(1001) << "\n";

    return 0;
}
