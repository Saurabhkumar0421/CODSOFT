#include <iostream>
#include <random>
using namespace std;

int main()
{
    random_device rd;
    mt19937 gen(rd());

    int min_value = 1;
    int max_value = 100;
    uniform_int_distribution<> distribution(min_value, max_value);

    int random_number = distribution(gen);

    int guess;
    int attempt = 10;
    int count = 1;

    do
    {
        cout << "Guess the number: ";
        cin >> guess;

        if (guess == random_number)
        {
            cout << "You Got the right one in " << count << " attempt" << endl;
            break;
        }
        else if (guess > random_number)
        {
            cout << "Guessed number is high please enter small number" << endl;
            count++;
            attempt--;
        }
        else if (guess < random_number)
        {
            cout << "Guessed number is low please enter large number" << endl;
            count++;
            attempt--;
        }
        if (attempt == 0)
        {
            cout << "Attempt end" << endl;
            break;
        }
    } while (random_number != guess && attempt != 0);

    return 0;
}
