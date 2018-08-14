#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Rating{
	int pos;
	int val;
	bool operator<(const Rating& r) const
	{
		if (val < r.val)
			return true;
		return false;
	}
};
/*
	Ý tưởng của bài toán:
	- Đọc dữ liệu đầu vào lưu lại cả giá trị và vị trí tương ứng
	- Sắp xếp theo giá trị
	- Dùng con trỏ left (l) để đánh dấu khoảng trên mảng đã sắp xếp 
	  để tìm ra các phần tử có rating cao hơn.
	  Nếu phần tử nào có rating cao hơn, cập nhật lại giá trị position cho vị
	  trí tương ứng vào mảng kết quả(res)
	 - In ra kết quả
	 - Độ phức tạp: O(nlogn) + O(n) + O(n) = O(nlogn)
*/
int main()
{
	int n;
	int tmp,l = 0, pos = 0;
	int res[2000] = {0};
	vector<Rating> lst_rating;
	//Read input data
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>tmp;
		Rating rat;

		rat.val = tmp;
		rat.pos = i;
		lst_rating.push_back(rat);
	}
	//Sort rating
	sort(lst_rating.begin(), lst_rating.end());

	for(int i = 0; i < lst_rating.size();i++)
	{
		int val = lst_rating[i].val;
		if(lst_rating[l].val < val)
		{
			pos = 1 + (n - i);
			while(l < i)
			{
				res[lst_rating[l].pos] = pos;
				l++;
			}
		}

	}
	for(int i = l; i < n; i++)
	{
		res[lst_rating[i].pos] = 1;
	}
	for(int i = 0; i < n;i++)
	{
		cout<<res[i] << " ";
	}
	return 0;
}