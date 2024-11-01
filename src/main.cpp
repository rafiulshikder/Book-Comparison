#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <list>
#include <set>
using namespace std;

static list<string> bookNames = {
    "Cats by Moncrif.txt",
    "Foxes Book of Martyrs Part 1.txt",
    "Foxes Book of Martyrs Part 2.txt",
    "Foxes Book of Martyrs Part 3.txt",
    "Foxes Book of Martyrs Part 4.txt",
    "Foxes Book of Martyrs Part 5.txt",
    "Foxes Book of Martyrs Part 6.txt",
    "Gerards Herbal Vol. 1.txt",
    "Gerards Herbal Vol. 2.txt",
    "Gerard's Herbal Vol. 3.txt",
    "Gerards Herbal Vol.4.txt",
    "Gil Blas.txt",
    "Gossip in a Library.txt",
    "Hudibras.txt",
    "King of the Beggars.txt",
    "Knocknagow.txt",
    "Les Chats par Moncrif.txt",
    "Love and Madness - Herbert Croft.txt",
    "Lives and Anecdotes of Misers.txt",
    "Memoirs of Laetitia Pilkington V 1.txt",
    "Memoirs of Laetitia Pilkington V 2.txt",
    "Memoirs of Laetitia Pilkington V 3.txt",
    "Memoirs of Mrs Margaret Leeson - Peg Plunkett.txt",
    "Monro his Expedition.txt",
    "Mrs Beetons Book of Household Management.txt",
    "Out of the Hurly-Burly.txt",
    "Percys Reliques.txt",
    "Pompey the Little.txt",
    "Radical Pamphlets from the English Civil War.txt",
    "Scepsis Scientifica.txt",
    "The Anatomy of Melancholy Part 1.txt",
    "The Anatomy of Melancholy Part 2.txt",
    "The Anatomy of Melancholy Part 3.txt",
    "The Complete Cony-catching.txt",
    "The Consolation of Philosophy.txt",
    "The Covent Garden Calendar.txt",
    "The Devil on Two Sticks.txt",
    "The Diary of a Lover of Literature.txt",
    "The History Of Ireland - Geoffrey Keating.txt",
    "The History of the Human Heart.txt",
    "The Ingoldsby Legends.txt",
    "The Life of Beau Nash.txt",
    "The Life of john Buncle by Thomas Amory.txt",
    "The Life of King Richard III.txt",
    "The Life of Pico della Mirandola.txt",
    "The Martyrdom of Man.txt",
    "The Masterpiece of Aristotle.txt",
    "The Memoirs of Count Boruwlaski.txt",
    "The Metamorphosis of Ajax.txt",
    "The Newgate Calendar - Supplement 3.txt",
    "The Newgate Calendar Supplement 2.txt",
    "The Newgate Calendar Supplement.txt",
    "The Newgate Calendar V 1.txt",
    "The Newgate Calendar V 2.txt",
    "The Newgate Calendar V 3.txt",
    "The Newgate Calendar V 4.txt",
    "The Newgate Calendar V 5.txt",
    "The Newgate Calendar V 6.txt",
    "The Poems of Ossian.txt",
    "The Poetical Works of John Skelton.txt",
    "The Protestant Reformation.txt",
    "The Real Story of John Carteret Pilkington.txt",
    "The Rowley Poems.txt",
    "The Silver Fox.txt"};

class BookComparison
{
    map<string, list<string>> bookWords;
    map<string, map<string, int>> bookWordsCount;
    map<string, map<string, float>> bookWordsNormalScore;
    map<string, list<string>> bookMostUsedWords;

public:
    void addBookWords(list<string> &bookNames = bookNames)
    {
        set<string> excludeWords = {"a", "an", "the"};
        for (const string &bookName : bookNames)
        {
            ifstream file(bookName);
            if (file.is_open())
            {
                list<string> words;
                string word;
                while (file >> word)
                {
                    // Convert word to lowercase
                    transform(word.begin(), word.end(), word.begin(), ::tolower);
                    // Remove punctuation from the word
                    word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
                    if (excludeWords.find(word) == excludeWords.end())
                    {
                        words.push_back(word);
                    }
                }
                bookWords[bookName] = words;
                file.close();
            }
            // cout<<file.is_open()<<bookName<<endl;
            // file.close();
        }
    }
    void addBookWordsCount()
    {
        for (const auto &book : bookWords)
        {
            map<string, int> wordCount;
            int totalWords = 0;
            
            // Count frequency of each word
            for (const auto &word : book.second)
            {
                wordCount[word]++;
                totalWords++;
            }
            
            // Add total word count
            wordCount["count"] = totalWords;
            
            // Store in bookWordsCount map
            bookWordsCount[book.first] = wordCount;
        }
    }
    void displayBookWords() {
        for (const auto& book : bookWordsCount) {
            cout << "Book: " << book.first << endl;
            cout << "Word frequencies:" << endl;
            for (const auto& word : book.second) {
                if (word.first != "count") {
                    cout << word.first << ": " << word.second << endl;
                }
            }
            cout << "Total words: " << book.second.at("count") << endl;
            cout << endl;
        }
    }

};

int
main()
{
    BookComparison book;
    book.addBookWords();
    book.addBookWordsCount();
    book.displayBookWords();
}