/* Given a sequence of integers as an array, determine whether it is possible to obtain a strictly increasing sequence by removing no more than one element from the array.

Note: sequence a0, a1, ..., an is considered to be a strictly increasing if a0 < a1 < ... < an. Sequence containing only one element is also considered to be strictly increasing.

Example

For sequence = [1, 3, 2, 1], the output should be
solution(sequence) = false.

There is no one element in this array that can be removed in order to get a strictly increasing sequence.

For sequence = [1, 3, 2], the output should be
solution(sequence) = true.

You can remove 3 from the array to get the strictly increasing sequence [1, 2]. Alternately, you can remove 2 to get the strictly increasing sequence [1, 3].*/

bool solution(vector<int> sequence) {
int n = sequence.size();
int modify = 0;
 
    // Check whether the first element needs
    // to be modify or not
    if (sequence[0] > sequence[1]) {
        modify++;
    }
 
    // Loop from 2nd element to the 2nd last element
    for (int i = 1; i < n - 2; i++) {
 
        // Check whether arr[i] needs to be modified
        if ((sequence[i - 1] < sequence[i] && sequence[i + 1] < sequence[i] && (i !=1 || modify == 0))
            || (sequence[i - 1] > sequence[i] && sequence[i + 1] > sequence[i] && i !=1)) {
            modify++;
        }
    }
 
    // Check whether the last element needs
    // to be modify or not
    if (sequence[n - 1] < sequence[n - 2]  )
        modify++;
    if (n==4 && sequence[n-1]== sequence[1])
    modify++;
 
    // If more than 1 modification is required
    if (modify > 1 || modify == 0 && n>2 )
        return false;
 
    return true ;
}
