1. Student Information
Easy
Class
Create a class Student with name, age, and marks. 
Use a constructor to initialize the values and a display() method to print them.
Input: No input required. Create an object with your own values.

#include<bits/stdc++.h>
using namespace std;
class Student{
    public:
        string name;
        int age;
        double marks;
        Student(string n, int a , double m){
            name = n;
            age = a;
            marks = m;
        }
    void display(){
        cout<<name<<" "<<age<<" "<<marks;
        cout<<endl;
    }
};
int main(){
    Student s1("Xavier",23,96.75);
    s1.display();
    Student s2("Sudipto",28,99.99);
    s2.display();
}

2. Rectangle Area
Easy
Class
Create a class Rectangle with length and width. 
Write a method that returns the area of the rectangle.
Input: length = 10, width = 5

#include<bits/stdc++.h>
using namespace std;
class Rectangle{
    public:
        int length , width;
    void display(){
        cout<<"Area of the rectangle: "<<(length*width)<<endl;
    }
};
int main(){
    Rectangle r1;
    r1.length = 10;
    r1.width = 5;
    r1.display();
    
}

3. Generic Box
Easy
Template Class
Create a template class Box<T> that stores one value and has a display() method. 
Test it with int, double, and string.

Input: 10, 3.14, "Hello"

#include<bits/stdc++.h>
using namespace std;
template<typename T>
void display(T x){
    cout<<x<<endl;
}
int main(){
    display(10);
    display(3.14);
    display("Hello");
}

4. Generic Maximum
Easy
Template Function
Write a template function maximum(T a, T b) that returns the larger value. Test it with integers and doubles.

Input: 10 20 3.5 2.1

#include<bits/stdc++.h>
using namespace std;
template<typename T>


void functionMaximum(T a , T b){
    if(a>b){
        cout<<a<<endl;
    }else{
        cout<<b<<endl;
    }
}
int main(){
    functionMaximum(10,20);
    functionMaximum(3.5,2.1);
    return 0;
}

5. Vector Operations
Easy
Vector
Create a vector of integers. Read n values, print the vector, 
then add one value at the end and remove the last element. 
Print the final vector.

Input: 5 10 20 30 40 50 Add: 60 Remove last

Expected output:

10 20 30 40 50

#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(5);
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    for(int x:v){
        cout<<x<<" ";
    }
}

//push_back(x)---> add x at the end
//pop_back(x)---> delete last element
//empty()--->Check whether empty or not
//size()--->Number of elements
//front()---> Front Element
//back()---> Back Element

// Stack
// LIFO = Last In , First Out
// push---> Adds an element on top of the stack.
// pop()---> Remove the top element from the stack.
// top()---> Top Element 
#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout<<st.top()<<endl;

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

// Queue--->FIFO ---> First In , First Out
// push---> Insert Element 
// pop()---> First Element Out
// front()--->Showing first element 
// back()--->Showing last element 
// empty()---> Check whether empty or not 
// size()---> Number of elements 
#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<int>q ;
    q. push(3);
    q. push(6);
    q. push(9);
    q. push(12);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int>s;
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    for(auto it=s.begin();it!=s.end();it++){
        cout<<*it<<" ";
    }

}

//6. Reverse a String
//Medium
//Stack
//Use a stack<char> to reverse a string. 
//Push every character, then pop and print the characters.

//Input: hello

//Expected output:

//olleh
#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<char> s;
    s.push('h');
    s.push('e');
    s.push('l');
    s.push('l');
    s.push('o');
    while(!s.empty()){
        cout<<s.top()<<"";
        s.pop();
    }
}

//7. Queue Simulation
//Medium
//Queue
//Use a queue<int>. Insert n numbers, then remove and print every number in FIFO order.

//Input: 5 10 20 30 40 50

//Expected output:

//10 20 30 40 50
#include<bits/stdc++.h>
using namespace std;
int main(){
    
    queue<int> q ;
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}

#include<bits/stdc++.h>
using namespace std;
class Student{
    public:
       string name;
       int id;
       double marks;
    Student(string n , int i, double m){
        name = n;
        id = i ;
        marks = m;
    }
    void display(){
        cout<<name<<" "<<id<<" "<<marks;
    }
};
int main(){
    Student s1("X",4509,89.90);
    s1.display();
    return 0;
}
