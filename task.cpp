/*�����ܣ�����ʵ��ɱ�����ĺ���,�Լ��ɱ�����ĺ������.
*�ɱ��������void my_sum(int count, ...);
*��������Ĺ����Ǽ����������ĺ͡�
*����count�ǽ�Ҫ��͵���������Ŀ��
*�����Ĳ����ǿɱ��,���е�һ��������char*�Ĳ�����������ʾ��
*����Ĳ����ֱ��Ǵ���͵�������һ��count����
*/

#include <stdarg.h>
#include <stdio.h>

void my_sum(int count, ...);

int main(int argc, char *argv[])
{
        int count = 5;
        printf("compute sum of %d numbers.\n",count);
        my_sum(count,"the sum of numbers is:", 1, 2, 3, 4, 5);
        return 0;
}

void my_sum(int count, ...)
{
        //��Ҫ���������Ҫ��ĳ���ɱ������ָ�����Ϣ
        va_list ap;
        char *prompt;
        int sum = 0;

        //��ʼ�ĳ�ʼ��������ap����ָ��ɱ������ָ�����Ϣ��count�ǵ�ǰ���������һ���ǿɱ�Ĳ���(�������ܶ�λ).
        va_start(ap, count);

        //��ȡ��������һ���ɱ������ֵ����һ��������ap����˵�ˣ��ڶ���������Ҫ��ȡ�Ĳ��������͡�
        //�����ĵ����������ָ�������ˣ�����û����һ���ɱ�����ˣ���ô���صĽ��������ġ�
        prompt = va_arg(ap, char*);
        printf("%s\n", prompt);

        int i;
        for(i = 0; i < count; ++i)
        {
                sum += va_arg(ap, int);
        }

        //ʹ����ɱ����֮��Ҫ��������ͷ���Դ
        va_end(ap);
        printf("%d\n",sum);

}