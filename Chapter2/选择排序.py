def findSmallest(arr):
    smallest = arr[0]
    smallest_index = 0
    for i in range(1,len(arr)):
        if arr[i]<smallest:
            smallest = arr[i]
            smallest_index = i
    return smallest_index

def selectionSort(arr):
    newArr = []
    for i in range(len(arr)):
        smallest = findSmallest(arr)
        newArr.append(arr.pop(smallest))
    #     pop(i)移除arr中索引为i的元素,并返回该元素的值
    #     append(x)将x添加到列表newArr的末尾
    return newArr
print(selectionSort([5,3,6,2,10]))
