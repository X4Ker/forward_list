#include <iostream>

using namespace std;

struct node_t {
    int value;
    node_t * next;
};

void add( node_t * & head, int value )
{
    node_t * node = new node_t;
    node->value = value;
    node->next = nullptr;

    if( head == nullptr ) {
        head = node;
        return;
    }

    node_t * last = head;
    while( last->next ) {
        last = last->next;
    }

    last->next = node;
}

void destroy(node_t * & head){

    if(head){
        node_t * next = head->next;
        delete head;
        head = next;
    }
}

node_t * advance( node_t * node, unsigned int step ) {
    node_t *result = node;
    for (unsigned int i = 0; i < step; ++i) {
        result = result->next;
    }

    return result;
}

unsigned int length( node_t * head )
{
    unsigned int size = 0;
    node_t * cur = head;
    while( cur ){
        cur = cur->next;
        ++size;
    }

    return size;
}

void reverse(node_t * head){
    unsigned int size = length( head );
    for( unsigned int i = 0; i < size / 2; ++i ) {

        std::swap( advance( head, i )->value, advance( head, size - 1 - i )->value );
    }
}

void write( node_t * & head)
{
    node_t * p;
    p=head;

    while (p != NULL) {
        cout << "+---+" << "    ";
        p=p->next;
    }
    p=head;
    cout << endl;

    while (p != NULL) {
        cout << "| " << p->value << " |";
        p=p->next;
        if (p != NULL) {
            cout << "--->";
        }
    }
    p=head;
    cout << endl;

    while (p != NULL) {
        cout << "+---+" << "    ";
        p=p->next;
    }
    cout << endl;
}



int main()
{
    node_t * head = nullptr;

    bool q = true;
    int a;
    char symbol;
    while (q){
        cin >> symbol;
        switch(symbol){
            case '+':
                cin >> a;
                add( head, a );
                write(head);
            break;

            case '-':
                destroy(head);
                write(head);
                break;

            case '=':
                write(head);
                break;

            case '/':
                reverse(head);
                write(head);
                break;

            case 'q':
                q = false;
                break;
        }
    }


    return 0;
}
