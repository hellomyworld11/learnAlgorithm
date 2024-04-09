/**
 * File: quick_sort.cpp
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

#include "../utils/common.hpp"

/* ���������� */
class QuickSort {
private:
    /* Ԫ�ؽ��� */
    static void swap(vector<int> &nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    /* �ڱ����� */
    static int partition(vector<int> &nums, int left, int right) {
        // �� nums[left] Ϊ��׼��
        int i = left, j = right;
        while (i < j) {
            while (i < j && nums[j] >= nums[left])
                j--; // �����������׸�С�ڻ�׼����Ԫ��
            while (i < j && nums[i] <= nums[left])
                i++;          // �����������׸����ڻ�׼����Ԫ��
            swap(nums, i, j); // ����������Ԫ��
        }
        swap(nums, i, left); // ����׼����������������ķֽ���
        return i;            // ���ػ�׼��������
    }

public:
    /* �������� */
    static void quickSort(vector<int> &nums, int left, int right) {
        // �����鳤��Ϊ 1 ʱ��ֹ�ݹ�
        if (left >= right)
            return;
        // �ڱ�����
        int pivot = partition(nums, left, right);
        // �ݹ��������顢��������
        quickSort(nums, left, pivot - 1);
        quickSort(nums, pivot + 1, right);
    }
};

/* ���������ࣨ��λ��׼���Ż��� */
class QuickSortMedian {
private:
    /* Ԫ�ؽ��� */
    static void swap(vector<int> &nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    /* ѡȡ������ѡԪ�ص���λ�� */
    static int medianThree(vector<int> &nums, int left, int mid, int right) {
        int l = nums[left], m = nums[mid], r = nums[right];
        if ((l <= m && m <= r) || (r <= m && m <= l))
            return mid; // m �� l �� r ֮��
        if ((m <= l && l <= r) || (r <= l && l <= m))
            return left; // l �� m �� r ֮��
        return right;
    }

    /* �ڱ����֣�����ȡ��ֵ�� */
    static int partition(vector<int> &nums, int left, int right) {
        // ѡȡ������ѡԪ�ص���λ��
        int med = medianThree(nums, left, (left + right) / 2, right);
        // ����λ�����������������
        swap(nums, left, med);
        // �� nums[left] Ϊ��׼��
        int i = left, j = right;
        while (i < j) {
            while (i < j && nums[j] >= nums[left])
                j--; // �����������׸�С�ڻ�׼����Ԫ��
            while (i < j && nums[i] <= nums[left])
                i++;          // �����������׸����ڻ�׼����Ԫ��
            swap(nums, i, j); // ����������Ԫ��
        }
        swap(nums, i, left); // ����׼����������������ķֽ���
        return i;            // ���ػ�׼��������
    }

public:
    /* �������� */
    static void quickSort(vector<int> &nums, int left, int right) {
        // �����鳤��Ϊ 1 ʱ��ֹ�ݹ�
        if (left >= right)
            return;
        // �ڱ�����
        int pivot = partition(nums, left, right);
        // �ݹ��������顢��������
        quickSort(nums, left, pivot - 1);
        quickSort(nums, pivot + 1, right);
    }
};

/* ���������ࣨβ�ݹ��Ż��� */
class QuickSortTailCall {
private:
    /* Ԫ�ؽ��� */
    static void swap(vector<int> &nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    /* �ڱ����� */
    static int partition(vector<int> &nums, int left, int right) {
        // �� nums[left] Ϊ��׼��
        int i = left, j = right;
        while (i < j) {
            while (i < j && nums[j] >= nums[left])
                j--; // �����������׸�С�ڻ�׼����Ԫ��
            while (i < j && nums[i] <= nums[left])
                i++;          // �����������׸����ڻ�׼����Ԫ��
            swap(nums, i, j); // ����������Ԫ��
        }
        swap(nums, i, left); // ����׼����������������ķֽ���
        return i;            // ���ػ�׼��������
    }

public:
    /* ��������β�ݹ��Ż��� */
    static void quickSort(vector<int> &nums, int left, int right) {
        // �����鳤��Ϊ 1 ʱ��ֹ
        while (left < right) {
            // �ڱ����ֲ���
            int pivot = partition(nums, left, right);
            // �������������н϶̵��Ǹ�ִ�п�������
            if (pivot - left < right - pivot) {
                quickSort(nums, left, pivot - 1); // �ݹ�������������
                left = pivot + 1;                 // ʣ��δ��������Ϊ [pivot + 1, right]
            } else {
                quickSort(nums, pivot + 1, right); // �ݹ�������������
                right = pivot - 1;                 // ʣ��δ��������Ϊ [left, pivot - 1]
            }
        }
    }
};

/* Driver Code */
int main() {
    /* �������� */
    vector<int> nums{2, 4, 1, 0, 3, 5};
    QuickSort::quickSort(nums, 0, nums.size() - 1);
    cout << "����������ɺ� nums = ";
    printVector(nums);

    /* ����������λ��׼���Ż��� */
    vector<int> nums1 = {2, 4, 1, 0, 3, 5};
    QuickSortMedian::quickSort(nums1, 0, nums1.size() - 1);
    cout << "����������λ��׼���Ż�����ɺ� nums = ";
    printVector(nums);

    /* ��������β�ݹ��Ż��� */
    vector<int> nums2 = {2, 4, 1, 0, 3, 5};
    QuickSortTailCall::quickSort(nums2, 0, nums2.size() - 1);
    cout << "��������β�ݹ��Ż�����ɺ� nums = ";
    printVector(nums);

    return 0;
}
