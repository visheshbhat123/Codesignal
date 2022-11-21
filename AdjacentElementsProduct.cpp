/*Given an array of integers, find the pair of adjacent elements that has the largest product and return that product.

Example

For inputArray = [3, 6, -2, -5, 7, 3], the output should be
solution(inputArray) = 21.

7 and 3 produce the largest product.*/

int solution(vector<int> inputArray) {
int n = inputArray.size();
  int a = inputArray[0], b = inputArray[1];
  int p =a*b;
    for (int i=1; i<n-1; i++)
    {
        /*for (int j=i+1; j<n; j++)
        {
            if (inputArray[i]*inputArray[j] > a*b)
             {
                a = inputArray[i];
                b = inputArray[j];
                p = a*b;
             }
        }*/
        if (inputArray[i]*inputArray[i+1] > a*b)
             {
                a = inputArray[i];
                b = inputArray[i+1];
                p = a*b;
             }
    }
    return p;
}
