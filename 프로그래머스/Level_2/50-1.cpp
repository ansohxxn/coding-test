#include <string>
#include <vector>

using namespace std;

class Node
{
public:
    string city;
    Node* nextNode = NULL;
    Node* prevNode = NULL;
};

class LinkedList
{
public:
    Node* head = NULL;
    Node* tail = NULL;
    int size = 0;

    void AddLast(string _city)
    {
        size++;

        Node* newNode = new Node;
        newNode->city = _city;
        
        if (head == NULL) 
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->nextNode = newNode;
            newNode->prevNode = tail;

            tail = newNode;
        }
    }

    void Remove(Node* node)
    {
        size--;

        if (node == head)
            head = node->nextNode;
        if (node == tail)
            tail = node->prevNode;
        if (node->prevNode != NULL)
            node->prevNode->nextNode = node->nextNode;
        if (node->nextNode != NULL)
            node->nextNode->prevNode = node->prevNode;
        
        delete node;
    }

    Node* Search(string _city)
    {
        Node* ptr = head;
        while (ptr != NULL)
        {
            if (isEqual(ptr->city, _city)) return ptr;
            ptr = ptr->nextNode;
        }
        return NULL;
    }
    
    bool isEqual(string a, string b)
    {
        if (a.length() != b.length()) return false;
        
        for(int i = 0; i < a.length(); i++)
        {
            if (a[i] == b[i]) continue;
            else if (a[i] - b[i] == -32 || a[i] - b[i] == 32) continue;
            
            return false;
        }
        
        return true;
    }
};

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    LinkedList cache;
    for (int i = 0; i < cities.size(); i++)
    {
        Node* cityInCache = cache.Search(cities[i]);

        if (cityInCache == NULL)
        {
            answer += 5;
            if (cache.size < cacheSize)
                cache.AddLast(cities[i]);
            else if (cache.size == cacheSize && cacheSize > 0)
            {
                cache.Remove(cache.head);
                cache.AddLast(cities[i]);
            }
        }
        else
        {
            answer += 1;
            cache.Remove(cityInCache);
            cache.AddLast(cities[i]);
        }
    }

    return answer;
}