#include <iostream>
#include <string>
using namespace std;

class BubbleShooter {
private:
    string row;

public:
    BubbleShooter() {
        row = "RGBGR";
    }

    void display() {
        cout << "\nCurrent Row:\n  ";
        for (int i = 0; i < row.length(); i++) {
            cout << i << " ";
        }
        cout << "\n  ";
        for (int i = 0; i < row.length(); i++) {
            cout << row[i] << " ";
        }
        cout << "\n";
    }

    void shoot(char bubble, int position) {
        if (position < 0 || position > row.length()) {
            cout << "Invalid position!" << endl;
            return;
        }
        row.insert(position, 1, bubble);
        cout << "Shot " << bubble << " at position " << position << endl;
        popBubbles();
    }

    void popBubbles() {
        bool popped = false;
        int count = 1;
        for (int i = 1; i <= row.length(); i++) {
            if (i < row.length() && row[i] == row[i - 1]) {
                count++;
            }
            else {
                if (count >= 3) {
                    row.erase(i - count, count);
                    cout << "💥 Popped " << count << " bubbles!" << endl;
                    popped = true;
                    break;
                }
                count = 1;
            }
        }
        if (popped)
            popBubbles();
    }

    bool isEmpty() {
        return row.empty();
    }

    int getRowLength() {
        return row.length();
    }
};

int main() {
    BubbleShooter game;
    char bubble;
    int position;

    cout << "🎯 Bubble Shooter (Text Version)\n";
    cout << "Shoot R/G/B bubbles at a position. Match 3+ to pop!\n";

    while (true) {
        game.display();

        if (game.isEmpty()) {
            cout << "🎉 You cleared all bubbles! You win!\n";
            break;
        }

        cout << "\nEnter bubble color (R/G/B): ";
        cin >> bubble;
        bubble = toupper(bubble);

        if (bubble != 'R' && bubble != 'G' && bubble != 'B') {
            cout << "❌ Invalid bubble color. Try again.\n";
            continue;
        }

        cout << "Enter position to shoot (0 to " << game.getRowLength() << "): ";
        cin >> position;

        game.shoot(bubble, position);
    }

    return 0;
}
