// #include <iostream>
// using namespace std;
// int main()
// {
//     int arr[] = {23,
//                  44,
//                  67,
//                  1,
//                  5,
//                  89,
//                  102,
//                  550,
//                  69,
//                  4};
//     int n = 10;
//     int first = arr[0], second = INT_MAX, third = INT_MAX;
//     if (first > arr[1])
//     {
//         second = first;
//         first = arr[1];
//     }
//     else
//     {
//         second = arr[1];
//     }
//     if (first > arr[2])
//     {
//         if (second > arr[2])
//         {
//             third = second;
//             second = first;
//             first = arr[2];
//         }
//         else
//         {
//             third = arr[2];
//         }
//     }
//     else
//     {
//         if (second > arr[2])
//         {
//             third = second;
//             second = arr[2];
//         }
//         else
//         {
//             third = arr[2];
//         }
//     }
//     for (int i = 3; i < n; i++)
//     {
//         if (first > arr[i])
//         {
//             if (second > arr[i])
//             {
//                 third = second;
//                 second = first;
//                 first = arr[i];
//             }
//             else
//             {
//                 third = arr[i];
//             }
//         }
//         else
//         {
//             if (second > arr[i])
//             {
//                 third = second;
//                 second = arr[i];
//             }
//             else
//             {
//                 third = arr[i];
//             }
//         }
//     }
//     cout << third;
// }
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
    for (int i = 0; i < n; i++)
        cout << arr[i];
    return 0;
}