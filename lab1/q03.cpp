#include <iostream>
#include <string>

using namespace std;

class Document {
private:
    string* content;

public:
    Document() : content(nullptr) {}
    Document(const string& text) : content(new string(text)) {}
    Document(const Document& obj) : content(new string(*obj.content)) {}
    ~Document() { 
        delete content; 
    }

    Document& operator=(const Document& obj) {
        if (this != &obj) {
            delete content;
            content = new string(*obj.content);
        }
        return *this;
    }

    void displayContent() const { 
        if (content) 
            cout << *content << endl; 
        else 
            cout << "No content to display." << endl;
    }

    void setContent(const string& text) {
        delete content;
        content = new string(text);
    }
};

int main() {
    Document doc1("Hello World!");
    Document doc2(doc1);            
    Document doc3;                  
    doc3 = doc1;                   

    doc1.setContent("Goodbye World!");  

    doc1.displayContent();  
    doc2.displayContent();  
    doc3.displayContent();  

    return 0;
}
