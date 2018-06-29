/*
* auth        : Jefung
* version     : v1.0
* description :
*
* analyse     :
*
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

class Node {
public:
    char name[50];
    char question[50];
    Node *yes;
    Node *no;
    Node() {
        name[0] = '\n';
        question[0] = '\n';
        yes = NULL;
        no = NULL;
    }
};

class AnimalClassify {
public:
    Node *root;
    AnimalClassify() {
        root = new Node;
    }
    void initByFile(const char *filename) {
        // ofstream out(filename);
        ifstream in(filename);
        char buffer[256];
        if(!in.eof()) {
            in.getline(buffer, 100);
            int i = 0;
            while(buffer[i]) {
                root->name[i] = buffer[i];
                i++;
            }
            root->name[i] = '\0';
            // cout << root->name << endl;
        }
        if(!in.eof()) {
            in.getline(buffer, 100);
            int i = 0;
            while(buffer[i]) {
                root->question[i] = buffer[i];
                i++;
            }
            root->question[i] = '\0';
            // cout << root->question << endl;
        }
        initByFileStream(in, root->yes);
        initByFileStream(in, root->no);
    }

    void exportData(const char *filename) {
        ofstream ofile(filename);
        preOrder(ofile);
    }


    void preOrder(ofstream &ofile, Node *p = NULL) {
        if(p == NULL)
            p = root;
        if(p->yes == NULL && p->no == NULL) {
            ofile << p->name << endl;
            ofile << p->question << endl;
            ofile << endl;
            ofile << endl;
            return;
        }
        ofile << p->name << endl;
        ofile << p->question << endl;
        if(p->yes != NULL)
            preOrder(ofile, p->yes);
        else {
            ofile << endl;
        }
        if(p->no != NULL)
            preOrder(ofile, p->no);
        else {
            ofile << endl;
        }
    }

    void startGuess(Node *p = NULL) {
        if(p == NULL)
            p = root;
        int answer;
        cout << "question: " << p->question << " :(1 or 0)" << endl;
        cin >> answer;
        while(answer != 0 && answer != 1) {
            cout << "please enter 1 or 0" << endl;
            cin >> answer;
        }
        int answer2;
        if(answer == 1) {
            cout << "name: " << p->name << " :(1 or 0)" << endl;
            cin >> answer2;

            while(answer2 != 0 && answer2 != 1) {
                cout << "please enter 1 or 0" << endl;
                cin >> answer2;
            }

            if(answer2 == 1) {
                cout << "guess successfully!!!" << endl;
                cout << "Do you want to guess again?(1 or 0)" << endl;
                int answer3;
                cin >> answer3;
                while(answer3 != 0 && answer3 != 1) {
                    cout << "please enter the right answer" << endl;
                    cin >> answer3;
                }
                if(answer3 == 1) {
                    cout << "restart guess" << endl;
                    startGuess();
                } else return;
            }
            if(answer2 == 0) {
                if(p->yes == NULL) {
                    addAnimal(p->yes);

                    cout << "Do you want to guess again?(1 or 0)" << endl;
                    int answer3;
                    cin >> answer3;
                    while(answer3 != 0 && answer3 != 1) {
                        cout << "please enter the right answer" << endl;
                        cin >> answer3;
                    }
                    if(answer3 == 1) {
                        cout << "restart guess" << endl;
                        startGuess();
                    } else return;
                }
                startGuess(p->yes);
            }

        } else {
            if(p->no == NULL) {
                addAnimal(p->no);
                cout << "Do you want to guess again?(1 or 0)" << endl;
                int answer3;
                cin >> answer3;
                while(answer3 != 0 && answer3 != 1) {
                    cout << "please enter the right answer" << endl;
                    cin >> answer3;
                }
                if(answer3 == 1) {
                    cout << "restart guess" << endl;
                    startGuess();
                } else return;

                // startGuess();
                // return;
            } else startGuess(p->no);
        }


    }

    void addAnimal(Node *&p) {
        p = new Node();
        cout << "enter the new question for the animal: ";
        cin >> p->question;
        cout << "enter the animal name: ";
        cin >> p->name;
    }
private:
    void initByFileStream(ifstream &instream, Node *&child) {
        char buffer[256];
        if(!instream.eof()) {
            instream.getline(buffer, 100);
            // 空行直接为空节点
            if(buffer[0] == '\0') {
                child = NULL;
                return;
            }
            child = new Node();
            int i = 0;
            while(buffer[i]) {
                child->name[i] = buffer[i];
                i++;
            }
            child->name[i] = '\0';
            // cout << "show.name:" << child->name << endl;;
        }
        if(!instream.eof()) {
            instream.getline(buffer, 100);
            int i = 0;
            while(buffer[i]) {
                child->question[i] = buffer[i];
                i++;
            }
            child->question[i] = '\0';
            // cout << "show.question:" << child->question << endl;;
        }
        initByFileStream(instream, child->yes);
        initByFileStream(instream, child->no);
    }

};
int main() {
    AnimalClassify AC = AnimalClassify();
    AC.initByFile("data.txt");
    AC.startGuess();
    AC.exportData("data.txt");
}
