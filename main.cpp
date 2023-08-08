
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Words Counter from a file
// using string stream buffer
// then convert it to string
// the .txt file should be in the same dir
// or provide the full path when prompted

int countCharacters(const string& text){ //send the original text
    return text.size(); // Returns the number of characters in the string
}

int countWords(const string& text){
    stringstream ss(text);
    string word;
    int wordCounter = 0;
    while(ss >> word) wordCounter++; //Count words separated by spaces
    return wordCounter;
}

int countSentences(const string& text){
    int sentenceCounter = 0;
    for(char character : text){
        if(character == '.' || character == '!' || character == '?' || character == ',')
            sentenceCounter++;
    }
    return sentenceCounter;
}

int main() {
    // prompt for the file name
    // default is the program dir

    string filename, textFileContent;
    cout<<"\t==================================\n";
    cout<<"\t          Words Counter           \n";
    cout<<"\t==================================\n";
    cout<<"Enter the name of the text [.txt] file: ";
    cin>>filename;

    ifstream inputTextFile(filename + ".txt");
    if(!inputTextFile)
        cout<<"Error Reading file, Please check on the file place and name.\n";

    stringstream buffer;
    buffer << inputTextFile.rdbuf(); // the contents of the file is read to a ss buffer
    textFileContent = buffer.str(); // then convert the contents to string
    inputTextFile.close();

    cout<<"------------------------------------------------------\n";
    cout<< "Characters: " << countCharacters(textFileContent)<<endl; //with spaces
    cout<< "Words: " << countWords(textFileContent)<<endl;
    cout<< "Sentences: " << countSentences(textFileContent)<<endl;
    cout<<"------------------------------------------------------\n";
    return 0;
}
