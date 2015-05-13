main.cc文件解决climbers_problem问题，测试案例没有去读文件，只是用到了input字符串数组作为输入

解决思路：用一个数组保存每一个小区间的最大高度，当从前一个小区间移动到后一个小区间的时候就加上这两个区间的高度差的绝对值。
最后再加上总的区间长度就得到答案。
比如当输入为“3\n1,3,2\n2,4,4\n6,7,5\n"，总共会有7个小区间（0，1），（1，2）...等。假设用position[i]表示第i个区间（i - 1, i)的最大高度，
比如position[3] = 4, position[7] = 6，最后只要从前往后遍历一遍区间就可以。

时间复杂度O(每个输入区间的长度和)
空间复杂度O(n)



题目内容请通过图片链接阅读：https://github.com/zieckey/interview/blob/master/climber_problem/The%20problem.png 
