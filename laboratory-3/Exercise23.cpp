#include <iostream>

using namespace std;

void printBinary(unsigned char x)
{
    int b;
    for (b = 2 * sizeof(int) - 1; b >= 0; b--)
    {
        cout << (((int)x & (1U << b)) > 0);
    }
}

int getSpecificBinary(unsigned char x, int pos)
{
    int b;
    for (b = 2 * sizeof(int) - 1; b >= 0; b--)
    {
        if (b != 8-pos)
        {
            continue;
        }
        return (((int)x & (1U << b)) > 0);
    }
}


int main()
{
    unsigned char z = 0x00;
    const int num_of_players = 4;
    int score[num_of_players];
    int previous_throw[num_of_players];
    bool is_ready[num_of_players];
    bool end_of_game = false;
    int board_size;
    cin >> board_size;

    

    int i = num_of_players-1;

    for (int j = 0; j < num_of_players; j++)
    {
        score[j] = 0;
        previous_throw[j] = 0;
        is_ready[j] = false;
    }

    while (!end_of_game)
    {
        char instruction;
        cin >> instruction;
        switch (instruction)
        {
            if (i < 0)
            {
                i = num_of_players-1;
            }

        case 'M':
        {
            int number;
            cin >> number;
            if (getSpecificBinary(z, 2*i+2) == 1)
            {
                score[i] += number;
                if (score[i] >= board_size)
                {
                    cout << "END OF GAME";
                    end_of_game = true;
                }

            }
            else if (number == 6 && previous_throw[i] == 1)
            {
                //is_ready[i] = true;
                int temp = pow(2, (i + 1) * 2 - 1);
                z = z | temp;
            }
            previous_throw[i] = number;
            i--;
            break;
        }
        case 'P':
        {
            i = num_of_players-1;
            for (auto sc : score)
            {
                cout << sc << " ";
            }
            printBinary(z);
            cout << '\n';
            break;
        }
        }
    }
}