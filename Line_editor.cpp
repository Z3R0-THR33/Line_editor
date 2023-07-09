#include <iostream>
#include <fstream>
#include <list>
#include <string>

using namespace std;

// TextEditor class to hold the list of strings
class TextEditor 
{
private:
    list<string> lines;

public:
    // Add a new line of text to the end of the list.
    void add() 
    {
        string line;
        cout << "Enter a line of text: ";
        cin.ignore();
        getline(cin, line);
        lines.push_back(line);
    }

    // Insert a new line of text at a specific position in the list.
    void insert() 
    {
        int line_num;
        string text;
        cout << "Enter line number to insert after: ";
        cin >> line_num;
        cin.ignore();  // Ignore the newline character left by cin
        cout << "Enter line of text to insert: ";
        getline(cin, text);
        auto iter = lines.begin();
        advance(iter, line_num - 1);
        lines.insert(iter, text);
    }

    // Delete a line of text at a specific position in the list.
    void remove() 
    {
        int line_num;
        cout << "Enter line number to delete: ";
        cin >> line_num;
        auto iter = lines.begin();
        advance(iter, line_num - 1);
        lines.erase(iter);
    }

    // Move a line of text from one position to another.
    void move() 
    {
        int src_line_num, dest_line_num;
        cout << "Enter line number to move: ";
        cin >> src_line_num;
        cout << "Enter line number to move after: ";
        cin >> dest_line_num;
        auto src_iter = lines.begin();
        advance(src_iter, src_line_num - 1);
        auto dest_iter = lines.begin();
        advance(dest_iter, dest_line_num);
        lines.splice(dest_iter, lines, src_iter);
    }

    // Replace the text in a specific line of the list.
    void replace() 
    {
        int line_num;
        string text;
        cout << "Enter line number to replace: ";
        cin >> line_num;
        cin.ignore();  // Ignore the newline character left by cin
        cout << "Enter new line of text: ";
        getline(cin, text);
        auto iter = lines.begin();
        advance(iter, line_num - 1);
        *iter = text;
    }

    // Print all lines of text in the list.
    void print() 
    {
        for (auto line : lines) {
            cout << line << endl;
        }
    }

    // Save all lines of text to a file.
    void save() 
    {
        string filename;
        cout << "Enter filename to save to: ";
        cin >> filename;
        ofstream file(filename);
        if (file.is_open()) {
            for (auto line : lines) {
                file << line << endl;
            }
            file.close();
            cout << "Saved to file " << filename << endl;
        } else {
            cout << "Unable to open file " << filename << endl;
        }
    }

    // Open a file and read its contents into the list.
    void open() 
    {
        string filename;
        cout << "Enter filename to open: ";
        cin >> filename;
        ifstream file(filename);
        if (file.is_open()) 
        {
            lines.clear();
            string line;
            while (getline(file, line)) {
                lines.push_back(line);
            }
            file.close();
            cout << "Opened file " << filename << endl;
        } else 
        {
            cout << "Unable to open file " << filename << endl;
        }
    }
};

int main() 
{
    TextEditor editor;
    char choice;
    do {
        cout << "Choose an option:" << endl;
        cout << "a - Add a new line of text" << endl;
        cout << "i - Insert a line of text" << endl;
        cout << "r - Remove a line of text" << endl;
        cout << "m - Move a line of text" << endl;
        cout << "p - Print all lines of text" << endl;
        cout << "s - Save to file" << endl;
        cout << "o - Open from file" << endl;
        cout << "q - Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 'a':
                editor.add();
                break;
            case 'i':
                editor.insert();
                break;
            case 'r':
                editor.remove();
                break;
            case 'm':
                editor.move();
                break;
            case 'p':
                editor.print();
                break;
            case 's':
                editor.save();
                break;
            case 'o':
                editor.open();
                break;
            case 'q':
                break;
            default:
                cout << "Invalid choice, please try again" << endl;
        }
    } while (choice != 'q');
    return 0;
}