#include <iostream>
using namespace std;
class player
{
private:
    string song;

public:
    player *before;
    player *next;
    player(string i)
    {
        song = i;
        before = NULL;
        next = NULL;
    }
    string curr_song()
    {
        return song;
    }
};
int main()
{
    int choice;
    string song;
    player *start = NULL;
    player *last = NULL;
    player *temp = start;
    bool flag = true;
    while (flag)
    {
        cout << "\nEnter the choice:\n1. play\n2. next\n3. prev\n 4. insert\n 5.exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (temp != NULL)
                cout << temp->curr_song() << endl;
            else
                cout << "No song\n";
            break;
        case 2:
            temp = temp->next;
            cout << temp->curr_song() << endl;
            break;
        case 3:
            temp = temp->before;
            cout << temp->curr_song() << endl;
            break;
        case 4:
        {
            cout << "Enter the song : ";
            cin >> song;
            player *p_new = new player(song);
            if (start == NULL)
            {
                start = p_new;
                start->next = p_new;
                last = p_new;
                last->before = p_new;
                temp = start;
            }
            else
            {
                last->next = p_new;
                p_new->before = last;
                p_new->next = start;
                last = p_new;
            }
        }
        break;

        default:
            flag = false;
            break;
        }
    }
    return 0;
}