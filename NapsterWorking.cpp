#include <iostream>
#include <stdlib.h>
#include <unordered_map>
using namespace std;

//node class declaration and fucntion creation for searching
class node{
private:
    int sNode;
    string owner;
    string ip;
public:
    string song;
    void searchSong(string song_Name,  unordered_map<string, node*> mapper);
    node *accessor(int sn, string own, string add, string song);
    void displayNode();
};

//search algorithm in hash tables
void node::searchSong(string song_Name, unordered_map<string, node*> mapper){
    unordered_map<string, node*>::const_iterator got = mapper.find(song_Name);
    if (got == mapper.end()) cout << "not found";
    else{
        cout << got->first << " can be downloaded from \n";
        cout<< "Machine: Node "<<got->second->sNode<<endl;
        cout<< "Owner: "<<got->second->owner<<endl;
        cout<< "Address: "<<got->second->ip<<endl;
        cout<<endl;
        song = got -> first;
    }
}

void node::displayNode(){
    cout<< "Machine: Node "<<this->sNode<<endl;
    cout<< "Owner: "<<this->owner<<endl;
    cout<< "Address: "<<this->ip<<endl;
    cout<< "Song: "<<this->song<<endl;
}

node* node::accessor(int sn, string own, string add, string sng){
    node *nn = new node;
    nn -> sNode = sn;
    nn -> owner = own;
    nn -> ip = add;
    nn -> song = sng;
    return nn;
}


int main(){
    //nodes declaration
    node *node1, *node2, *node3, *node4, *node5;
    string songName;
    node1 = node2 = node3 = node4 = node5 = new node;
    
    // nodes creation
    node1 = node1->accessor(1, "Harshu's macbook", "192.168.29.129","Chainsmokers");
    node2 = node2->accessor(2, "Dittu's macbook", "192.168.29.130","Imagine Dragons");
    node3 = node3->accessor(3, "Manu's macbook", "192.168.29.131","Avalons");
    node4 = node4->accessor(4, "Nano's macbook", "192.168.29.132","Backstreet Boys");
    node5 = node5->accessor(5, "Jaggu's macbook", "192.168.29.133","SnoopDog");
    
    // meta table declaration and feeding
    unordered_map<string, node*> meta_table = {
        // creating the centralised metadata hash table for storing songs info to nodes accordingly
        {"Chainsmokers",node1},
        {"ImagineDragons",node2},
        {"Avalons",node3},
        {"BackstreetBoys",node4},
        {"SnoopDog",node5}
    };
    
    //searching
    node3->displayNode();
    cout<<"Enter the song name : ";
    cin>>songName;
    
    cout<<endl<<endl;
    node3->searchSong(songName, meta_table);
    cout<<"DOWNLOAD COMPLETED!\n\n";
    node3->displayNode();
    return 0;
}
