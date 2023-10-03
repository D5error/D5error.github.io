int maxSubArray(int* nums, int numsSize)
{
    int maxSum=nums[0],i=0;
    while(i<numsSize&&nums[i]<=0)
    {
        maxSum=nums[i]>maxSum?nums[i]:maxSum;
        i++;
    }
    for(int lastSum=0;i<numsSize;)
    {
        int p1=lastSum,n=0,p2=0;
        while(i<numsSize&&nums[i]>=0)
        {
            p1+=nums[i];
            i++;
        }
        while(i<numsSize&&nums[i]<=0)
        {
            n+=nums[i];
            i++;
        }
        while(i<numsSize&&nums[i]>=0)
        {
            p2+=nums[i];
            i++;
        }
        if(n+p1>0&&n+p2>0)//ºÏ²¢
        {
            lastSum=p1+p2+n;
            maxSum=lastSum>maxSum?lastSum:maxSum;
        }
        else
        {
            maxSum=(maxSum>p1&&maxSum>p2)?maxSum:(p1>p2?p1:p2);
            lastSum=p2;
        }
    }
    return maxSum;
}