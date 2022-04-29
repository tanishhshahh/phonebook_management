#include <bits/stdc++.h>
using namespace std;
// global declaration of contact list
string contactList[] = {"phantom" , "phone","phul"};

struct TrieNode
{
    // every trie Node contains a Map 'child'
    // in which each alphabet points to another trie node
    unordered_map<char,TrieNode*> child;

    // 'lastLetter' is true if the node represents
    // end of a contact
    bool lastLetter   ;

    // Constructor
    TrieNode()
    {
        // Initializing all nodes as null
        for (char i = 'a'; i <= 'z'; i++)
            child[i] = NULL;

        lastLetter = false;
    }
};

// Making root NULL for ease so that it doesn't
// have to be passed to all functions.
TrieNode *root = NULL;

// Add contacts int trie node
void AddContact(string s)
{
    int length = s.length();

    // 'head' is used to iterate the Trie Nodes
    TrieNode *head = root;
    for (int i = 0; i < length; i++)
    {
        // Check if the s[i] is already present in
        // Trie
        TrieNode *nextNode = head->child[s[i]];
        if (nextNode == NULL)
        {
            // If not found then create a new TrieNode
            nextNode = new TrieNode();

            // Insert into the Map
            head->child[s[i]] = nextNode;
        }

        // Move the head, to point to next
        // Trie Node
        head = nextNode;

        // If its the last character of the string 's'
        // then mark 'lastLetter' as true
        if (i == length - 1)
            head->lastLetter = true;
    }
}

// This function simply displays all contacts in
//phone directory.
// teaverse current node. String 'pre'
// stands for string corelating to the path from
// root to currentNode.
void showContactsTil(TrieNode *currentNode, string pre)
{
    // Checking if string 'pre' ends here
    // If yes then display the string till now
    if (currentNode->lastLetter)
        cout << pre << endl;

    // Find the Nodes adjecent to the current
    // Node and then recursively call the function

   for (char i = 'a'; i <= 'z'; i++)
    {
        TrieNode *next = currentNode->child[i];
        if (next != NULL)
            showContactsTil(next, pre + (char)i);
    }
}

   //this function show contacts
    //as user inputs a letter, for example
    //if user inputs "phu" then first it will show
    //all contacts starting from p then from ph
    //and finally from phu if no contact is present
    //then is will tell no result is found.
void showContacts(string str)
{
    TrieNode *previousNode = root;

    string pre = "";
    int length = str.length();

    // Display the contact List for string formed
    // after entering every character
    int i;
    for (i=0; i<length; i++)
    {
        // 'pre' stores the string formed so far
        pre += (char)str[i];

        // Get the last character entered
        char lastChar = pre[i];

        // Find the Node corelating to the last
        // character of 'pre' which is pointed by
        // prevNode of the Trie
        TrieNode *currentNode = previousNode->child[lastChar];

        // If nothing found, then break the loop as
        // no more prefixes are going to be present.
        if (currentNode == NULL)
        {
            cout << "No result found "<<" " << pre
                 << endl;
            i++;
            break;
        }

  
        cout << "Suggesions for" <<" "<< pre<<" "
             << "are "<< endl;
        showContactsTil(currentNode, pre);

        // Change prevNode for next pre
        previousNode = currentNode;
    }

   
    for (; i<length; i++)
    {
        pre += (char)str[i];
        cout << "no contact found for"<<" " << pre
             << endl;
    }
}

// Insert all the Contacts into the Trie
void insertInDirectory(string contacts[],int n)
{
    // Initialize root Node
    root = new TrieNode();

    // Insert each contact into the trie
    for (int i = 0; i < n; i++)
        AddContact(contacts[i]);
}


int main()
{

    // Size of the Contact List
    int n = sizeof(contactList)/sizeof(string);


    insertInDirectory(contactList, n);

    string Search = "phum";


    showContacts(Search);

    return 0;
}