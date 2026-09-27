///1. A class is a blueprint for creating objects.

#include<iostream>
using namespace std;

class student{
    public:
        string name;
        int age;
        void display(){
            cout<<name<<" "<<age<<endl;
        }     
};
/// Class             Object
/// Student     ->    s1
/// (Blueprint)       (real object) 
int main(){
    student s1,s2;
    s1.name ="Sudipto";
    s1.age = 22;
    
    s1.display();

    s2.name = "Niloy";
    s2.age = 23;

    s2.display();
    return 0;
}

/// Class with Constructor
/// A constructor initializes an object.
#include<bits/stdc++.h>
using namespace std;

class student{
    public:
       string name;
       int age;
       /// Constructor

       student(string n , int a ){
        name = n ;
        age = a ;
       }
    void display(){
        cout<<name<<" "<<age<<endl;
    }
};

int main(){
    student s1("Sudipto", 22);
    s1.display();

    student s2("Niloy",23);
    s2.display();
}


/// Why do we need Template Class?
// Suppose you create a class called Box.
// You want:
// Box for int
// Box for double
// Box for string
// Without templates, you might have to create separate classes:
class IntBox {
    int value;
};

class DoubleBox {
    double value;
};

class StringBox {
    string value;
};
That's repetitive.

Instead, use a template.

/// Part 2 ---> Template Class
/// A template allows a class to work with different data types.
#include<bits/stdc++.h>
using namespace std;
/// How to build an template class

template<typename T>

class Box{
    public:
    T value;
    /// Constructor
    Box(T v){
        value = v ;
    }
    void display(){
        cout<<value<<endl;
    }
};
int main(){
    Box<double>b1(10);
    b1.display();
    Box<double>b2(2.33);
    b2.display();
    Box<string>b3("hello, cutie !");
    b3.display();
}
//4. Template Function

// Templates aren't only for classes.

// You can make template functions too.

#include<bits/stdc++.h>
using namespace std;
/// Template Function
template<typename T>
void print(T x){
    cout<<x<<endl;
}

int main(){
    print(10);
    print(3.14);
    print("Hello World");
}

//Part 3 — STL

//Now we reach STL.

//STL = Standard Template Library

//This is extremely important for competitive programming and DSA.

//STL gives you ready-made:

//Containers

vector
array
list
deque
stack
queue
priority_queue
set
map
unordered_set
unordered_map

Algorithms

sort()
reverse()
find()
binary_search()
max()
min()
count()

Iterators

Used to move through containers.
5. Why STL exists?

Imagine you need a dynamic array.

You could build one yourself.

But C++ already provides:

//vector?
vector<int>
//stack?
stack<int>
//queue?
queue<int>
//priority_queue?
priority_queue<int>
//Set?
set<int>
//Map?
map<int,string>
//So instead of implementing everything yourself:
You
 ↓
STL
 ↓
Ready-made data structures
 ↓
Solve problems faster

6. Vector — Most Important STL Container

Start with vector.

//Important vector functions
//Function               Meaning
//push_back(x)    -----  Add x at end
//pop_back()      -----  Remove last 
//size()          -----  Number of elements 
//empty()         -----  Check whether empty
//clear()         -----  Remove everything 
//front()         -----  First element 
//back()          -----  Last element 

#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    cout<<v[0]<<endl;
    cout<<v.size()<<endl;
    cout<<v.front()<<endl;
    cout<<v.back()<<endl;
    return 0;
}

//7. Stack 
// LIFO = Last In , First Out
// push ---> Adds an element on top of the stack.
// pop() ---> Removes the top element from the stack.
// top() ---> Top Element
// empty() ---> Check whether empty or not.
// size() ---> Number of elements.
#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout<<st.top()<<endl;

    cout<<st.size()<<endl;

    // Display the stack elements from top to bottom
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

//8. Queue

// Queue follows:

// FIFO = First In, First Out
//push()---> Insert Element
//pop()---> First Element Out
//front()---> Showing First Element 
//back()---> Showing Last Element
//empty()---> Check whether empty or not
//size()---> Number of elements 
#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout<<q.size()<<endl;
    cout<<q.back()<<endl;
    
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
   
}

//9. Priority Queue

//This is very important for DSA
//By default, the largest value comes first.
#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int> pq;
    pq.push(10);
    pq.push(50);
    pq.push(20);
    cout<<pq.top();
}

//10. Set

//A set stores unique elements in sorted order.
//Automatically Sorted.
//Duplicate are removed.

#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> s;
    s.insert(30);
    s.insert(10);
    s.insert(20);
    s.insert(10);
    for(int x : s){
        cout<<x<<" ";
    }
    // Using Iterators 
    for(set<int>::iterator it = s.begin();it!=s.end();it++){
        cout<<*it<<" "; 
    }
    return 0;
}

// 11. Map
// A map stores:
// KEY -> VALUE
#include<bits/stdc++.h>
using namespace std;
int main(){
    map<string , int> marks;
    marks["Sudipto"]=90;
    marks["Rahim"]=85;
    cout<<marks["Sudipto"];
}

// 13. Vector
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v = {1,2,3,4,5,6};
    //sort(v.begin(),v.end());
    //reverse(v.begin(),v.end());
    //find
    //find(v.begin(),v.end(),6);
    //Count
    //count(v.begin(),v.end(),5);
    for(auto it = v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
}

//14. Iterators

//This is another important STL concept.

//For:
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v={10,20,30};
    for(auto it = v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
}















