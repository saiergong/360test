#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define H_ARRAYSIZE(a) \
    ((sizeof(a) / sizeof(*(a))) / \
    static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))

int resolve(const char* input)
{
	int position[1000];
	memset(position, 0, sizeof(position));
	int p = 2;
	int answer = 0;

	int len = strlen(input);
	int last = -1;;
	while(p < len){
		int start = input[p] - '0';
		int end = input[p + 2] - '0';
		if(end > last)
			last = end;
		int height = input[p + 4] - '0';
		p += 6;
		for(int i = start + 1; i <= end; i++){
			position[i] = (position[i] > height) ? position[i] : height;
		}
	}
	answer += position[1];
	for(int i = 2; i <= last; i++){
		answer += abs(position[i] - position[i - 1]);
	}

	answer += position[last];
	if(last != -1)
		answer += last;
    return answer;
}

int main(int argc, char* argv[]) 
{
    const char* input[] = {
        "3\n1,3,2\n2,4,4\n6,7,5\n", //The giving example
        "1\n1,2,1\n",
        "2\n1,2,1\n2,3,2",
        "3\n1,2,1\n2,3,2\n3,6,1",
        "4\n1,2,1\n2,3,2\n3,6,1\n5,8,2",
        "5\n1,2,1\n2,3,2\n3,6,1\n5,8,2\n7,9,1",
        "1\n0,1,1",
        "2\n0,1,1\n2,4,3",
        "3\n0,1,1\n2,4,3\n3,5,1",
        "4\n0,1,1\n2,4,3\n3,5,1\n5,6,1",
        "5\n0,1,1\n2,4,3\n3,5,1\n5,6,1\n6,8,3",
        //TODO please add more test case here
        };
    int expectedSteps[] = {25, 4, 7, 10, 14, 15, 3, 12, 13, 14, 20};
    for (size_t i = 0; i < H_ARRAYSIZE(input); ++i)
    {
        assert(resolve(input[i]) == expectedSteps[i]);
    }
    return 0;
}
