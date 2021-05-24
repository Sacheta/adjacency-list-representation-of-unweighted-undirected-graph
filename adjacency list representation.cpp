//adjacency list implementation for undirected unweighted graph
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class graph{  //graph class
vector<vector<int> > arr;  //vector of vectors for adjacency list
public:
    graph(int a){  //default initializer
        arr.resize(a);

    }

    void addEdge(int a, int b){  //function to add an edge
        if(find(arr[a].begin(),arr[a].end(),b)!=arr[a].end()){  //to check if edge already exists
            cout<<"Already exists!"<<endl;
            return;
        };

            arr[a].push_back(b);  //adding edge
            arr[b].push_back(a);


    }
    void removeEdge(int a, int b){  //function to remover an edge

        auto d=find(arr[a].begin(),arr[a].end(),b);  //finding the edge
        arr[a].erase(d);  //removing the edge

        auto f=find(arr[b].begin(),arr[b].end(),a);
        arr[b].erase(f);

    }
    void displayGraph(){  //function to display our graph
        cout<<"----------------"<<endl;

        for(int i=0;i<arr.size();++i){
            for(int j=0;j<arr[i].size();++j)
                if(!j)
                    cout<<i<<"-> "<<arr[i][j]<<" ";  //to display the vertex and the element
                else
                    cout<<arr[i][j]<<" ";  //to display the element
        cout<<endl;
    }
    }

};

int main(){
    cout<<"Enter number of vertices: ";
    int n;
    cin>>n;
    graph g(n);  //declaring an object of graph
    cout<<"Make a selection: "<<endl;
    cout<<"1. Add an edge"<<endl;
    cout<<"2. Remove an edge"<<endl;
    cout<<"3. Display the graph"<<endl;
    int a;
    while(cin>>a){  //while input will be valid
        switch(a){
        case 1:
            int f,t;
            cout<<"Enter edge from: ";
            cin>>f;
            cout<<"Enter edge to: ";
            cin>>t;
            if((f>n-1)||(t>n-1)){  //checking if is out of range
            cout<<"Out of Range!"<<endl;
            }else{
            g.addEdge(f,t);  //calling addEdge() function
            cout<<"Edge added!"<<endl;}
            break;
        case 2:
            cout<<"Enter edge from: ";
            cin>>f;
            cout<<"Enter edge to: ";
            cin>>t;
            if((f>n-1)||(t>n-1)){  //checking if in the range
            cout<<"Out of Range!"<<endl;
            }else{
            g.removeEdge(f,t);
            cout<<"Edge removed!"<<endl;}
            break;
        case 3:
            g.displayGraph();  //display function
            break;
        default:  //default case
            cout<<"Invalid Input!"<<endl;
        }
    }

}

