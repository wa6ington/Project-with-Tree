#include <iostream>
#include <vector>

using namespace std;

struct Node {
    string question;
    Node* left;
    Node* right;
};

Node* newNode(string question) {
    Node* node = new Node;
    node->question = question;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

void addNode(Node*& root, string question, string character, vector<bool>& answers) {
    if (answers.empty()) {
        root = newNode(character);
        return;
    }

    bool answer = answers.front();
    answers.erase(answers.begin());

    if (root == nullptr) {
        root = newNode(question);
    } else {
        if (answer) {
            if (root->left == nullptr) {
                root->left = newNode(question);
            }
            addNode(root->left, question, character, answers);
        } else {
            if (root->right == nullptr) {
                root->right = newNode(question);
            }
            addNode(root->right, question, character, answers);
        }
    }
}

void playAkinator(Node* root) {
    if (root == nullptr) {
        cout << "I give up! You have chosen a too complex character." << endl;
        return;
    }

    cout << root->question << endl;
    char answer;
    while (true) {
        cout << "Please respond with 'y' for Yes or 'n' for No: ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            playAkinator(root->left);
            return;
        } else if (answer == 'n' || answer == 'N') {
            playAkinator(root->right);
            return;
        } else {
            cout << "Invalid input. ";
        }
    }
}


int main() {
    // Sample questions and answers for various characters
    vector<bool> answers1 = {true, false, true, true}; // Batman
    vector<bool> answers2 = {true, false, true, false, true}; // Superman
    vector<bool> answers3 = {true, false, true, false, false, true}; // Iron Man
    vector<bool> answers4 = {true, false, true, false, true}; // Spider-Man
    vector<bool> answers5 = {false, true, true, false}; // Harry Potter
    vector<bool> answers6 = {false, true, true, true}; // Hermione Granger
    vector<bool> answers7 = {true, false, true, false}; // Darth Vader
    vector<bool> answers8 = {true, false, true, false}; // Luke Skywalker
    vector<bool> answers9 = {true, false, true, false}; // James Bond
    vector<bool> answers10 = {true, false, true, false}; // Captain Jack Sparrow
    vector<bool> answers11 = {true, false, true, false}; // Sherlock Holmes
    vector<bool> answers12 = {true, false, true, false}; // Indiana Jones
    vector<bool> answers13 = {true, false, true, false}; // Ellen Ripley
    vector<bool> answers14 = {true, false, true, false}; // Forrest Gump
    vector<bool> answers15 = {true, false, true, false}; // Captain America
    vector<bool> answers16 = {true, false, true, false}; // Gandalf
    vector<bool> answers17 = {true, false, true, false}; // Frodo Baggins
    vector<bool> answers18 = {true, false, true, false}; // Legolas
    vector<bool> answers19 = {true, false, true, false}; // Jon Snow
    vector<bool> answers20 = {true, false, true, false}; // Daenerys Targaryen

    // Initialize the root node with the starting question
    Node* root = nullptr;
    addNode(root, "Is this a human?", "Batman", answers1);

    // Add nodes for other characters
    addNode(root->left, "Is this a superhero?", "Superman", answers2);
    addNode(root->left->left, "Does he wear an iron suit?", "Iron Man", answers3);
    addNode(root->left->right, "Does he wear a spider suit?", "Spider-Man", answers4); // Example

    addNode(root->right, "Is this a wizard?", "Harry Potter", answers5);
    addNode(root->right->left, "Is this a girl?", "Hermione Granger", answers6);
    addNode(root->right->right, "Is this a villain?", "Darth Vader", answers7); // Example

    addNode(root->left->left->left, "Is he from a galaxy far, far away?", "Luke Skywalker", answers8);
    addNode(root->left->left->left->left, "Is he a secret agent?", "James Bond", answers9);
    addNode(root->left->left->left->right, "Is he a pirate?", "Captain Jack Sparrow", answers10);

    addNode(root->left->left->right, "Does he solve mysteries?", "Sherlock Holmes", answers11);
    addNode(root->left->left->right->left, "Is he an archaeologist?", "Indiana Jones", answers12);
    addNode(root->left->left->right->right, "Is she fighting aliens?", "Ellen Ripley", answers13);
    addNode(root->left->left->right->left->left, "Is he mentally challenged?", "Forrest Gump", answers14);
    addNode(root->left->left->right->left->right, "Is he a super soldier?", "Captain America", answers15);

    addNode(root->right->left->left, "Does he wield a staff?", "Gandalf", answers16);
    addNode(root->right->left->left->left, "Is he on a quest to destroy a ring?", "Frodo Baggins", answers17);
    addNode(root->right->left->left->right, "Is he an expert archer?", "Legolas", answers18);
    addNode(root->right->right->left, "Does he know nothing?", "Jon Snow", answers19);
    addNode(root->right->right->right, "Is she the mother of dragons?", "Daenerys Targaryen", answers20);

    // Play the Akinator game
    playAkinator(root);

    return 0;
}
