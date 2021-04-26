def QuickSort(array, start, end):
    lengths = len(array)
    i = start
    j = end
    # 结束排序（左右两索引值见面，即相等，或者左索引>右索引）
    if i >= j:
        return    # 返回空即可
    # 保存首个数值（以首个数值作为基准）
    # 这个位置很重要，一定要在if i>=j判断语句之后，否则就索引溢出了
    pivot = array[i]
    # 一次排序，i和j的值不断的靠拢，然后最终停止，结束一次排序
    while i < j:
        # （从右往左）和最右边的比较，如果>=pivot,即满足要求，不需要交换，然后j-1，慢慢左移，即拿基准值与前一个值比较; 如果值<pivot，那么就交换位置
        while i < j and pivot <= array[j]:
            # print(pivot, array[j], '*' * 30)
            j -= 1
        array[i] = array[j]
        # 交换位置后，然后在和最左边的值开始比较，如果<=pivot,然后i+1，慢慢的和后一个值比较;如果值>pivot，那么就交换位置
        while i < j and pivot >= array[i]:
            # print(pivot, array[i], '*' * 30)
            i += 1
        array[j] = array[i]
    # 列表中索引i的位置为基准值，i左边序列都是小于基准值的，i右边序列都是大于基准值的，当前基准值的索引为i，之后不变
    array[i] = pivot
    # 左边排序
    QuickSort(array, start, i-1)
    # 右边排序
    QuickSort(array, i+1, end)

    #return array

if __name__ == "__main__":
    array =  list(map(int,input().split()))      
    
    print("Original array: ", array)
    
    
    QuickSort(array, 0, len(array)-1)
    print("QuickSort: ", array)
    a = eval(input())
    print(array[a-1])