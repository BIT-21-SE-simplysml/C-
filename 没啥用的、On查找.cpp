//������������λ��֮�����ݽ���
void swap(vector<int>& arr, int a, int b)
{
      int temp = arr[b];
      arr[b] = arr[a];
      arr[a] = temp;
}

//�����㷨
//���ػ������ֺ����ڵ��±�
int partition(int left, int right, int pivot_index, vector<int>& arr)
{
    int pivot = arr[pivot_index];
    swap(pivot_index, right) //�������������
    int save = left;
    
    for(int i = left; i <= right; i++)
    {
        if(arr[i] < pivot)
        {
             swap(save, i);
             save++;
        }
    }
    
    //��������save��ָ�����ݽ���
    swap(save, right);
    return save;
}

//����ѡ��
int quickSelect(int left, right, int k, vector<int>& arr)
{
     if(left == right)   //ֻ��һ��Ԫ��ʱ
     {
          return arr[left]; //ֱ�ӷ���
      }
      int pivot_index = (right + left)/2;
      
      //���л���
      pivot_index = partition(left, right, pivot_index, arr);
      
      if(k == pivot_index)
      {
          return arr[pivot_index];
      }
      if(k < pivot_index)
      {
          return quickSelect(left, pivot_index-1, k, arr);
      }
      
      return quickSelect(pivot_index+1, right, k, arr);
} 
