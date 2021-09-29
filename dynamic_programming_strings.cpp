#include<bits/stdc++.h>

using namespace std;

pair<int,string> lcs(string s1, string s2){
//	longest common subsequence of 2 strings
	int m = s1.length();
	int n = s2.length();
	int memory[m+1][n+1];
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0){
				memory[i][j]=0;
				continue;
			}
			if(s1[i-1]==s2[j-1]){ //taking s1s length as i-1 and j-1 length for s2;
				//both chars are same:
				memory[i][j] = memory[i-1][j-1]+1;
			}else{
				//both are different
				memory[i][j] = max(memory[i-1][j],max(memory[i][j-1],memory[i-1][j-1]));
			}
		}
	}
	string ans ="";
	int i =m, j=n;
	while(i>=0&& j>=0){
		if(s1[i-1]==s2[j-1]){
			ans+=s1[i-1];
			i--;
			j--;
		}else{
			if(memory[i-1][j]>memory[j-1][i]){
				i--;
			}else{
				j--;
			}
		}
	}
	reverse(ans.begin(), ans.end());
	return {memory[m][n],ans};
}

void lps(string s1, int n){
	//longest palindromic sub sequence from given string
	string s2 = s1;
	reverse(s2.begin(), s2.end());
	//finding lcs of s1 and s2;
	pair<int,string>ans = lcs(s1, s2);
	cout<<"Longest palindromic length is "<<ans.first<<endl;
	cout<<"longest palindromic sub sequence is "<<ans.second<<endl;
}

void longest_common_substring(string s1, string s2){
	//	longest common substring of 2 strings
	int m = s1.length();
	int n = s2.length();
	int memory[m+1][n+1];
	int ans = 0;
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0){
				memory[i][j]=0;
				continue;
			}
			if(s1[i-1]==s2[j-1]){ //taking s1s length as i-1 and j-1 length for s2;
				//both chars are same:
				memory[i][j] = memory[i-1][j-1]+1;
				if(memory[i][j]>ans){
				ans = memory[i][j];
			}	
			}else{
				//both are different
				memory[i][j] = 0;
			}
			
		}
	}
	cout<<" Length of longest common substring is "<<ans<<endl;
}

void shortest_common_superseq(string s1,string s2){
//	length of shortest_common_superseq is nothing but len(s1) + len(s2) - len(lcs(s1,s2));
//	s1 = abcdef
//	s2 = xyzdefch
//	ans = abcxyzdefch or xyzabcdefch
//	ans should have all letters of s1 and s2 (conitinuition is not necessary as it is subseq and not substring but order of coming of letters matters)
	int m = s1.length();
	int n = s2.length();
	
	pair<int,string>ans = lcs(s1,s2);
	cout<<"length of shortest_common_superseq is "<<ans.first<<endl;
	
	
}


int findOverlappingPair(string str1, string str2, string &str)
{
	int max = INT_MIN;
	int len1 = str1.length();
	int len2 = str2.length();
	for (int i = 1; i <=min(len1, len2); i++)
	{		//cmp str1 from index len1-i for length i with str2 from index 0 with length i
		if (str1.compare(len1-i, i, str2,0, i) == 0)
		{
			if (max < i)
			{
				max = i;
				str = str1 + str2.substr(i);
			}
		}
	}
	for (int i = 1; i <=min(len1, len2); i++)
	{
			//cmp str2 from index len2-i for length i with str1 from index 0 with length i
		if (str1.compare(0, i, str2, len2-i, i) == 0)
		{
			if (max < i)
			{
				max = i;
				str = str2 + str1.substr(i);
			}
		}
	}
	return max;
}
void shortest_common_superstring(string arr[]){
//	string arr[]={"abc","xyzabc","demtor","pritor","prefix","suffix"};
	int len = 5;
	while(len != 1)
	{
		int max = INT_MIN;
		int l, r;
		string resStr;
		for (int i = 0; i < len; i++)
		{
			for (int j = i + 1; j < len; j++)
			{
				string str;
				int res = findOverlappingPair(arr[i],arr[j], str);//res = 3, str = 
				if (max < res)
				{
					max = res;//3
					resStr.assign(str);//store 0 and 1st string merged(str) in resStr
					l = i, r = j;//l=0,r=1
				}
			}
		}
		len--;
		if (max == INT_MIN)
			arr[0] += arr[len];
		else
		{
			arr[l] = resStr;//put merged string in place of first string that has been merged
			arr[r] = arr[len];//put last element of arr in place of second string that has been merged
		}
	}
//	return arr[0];
}

void  Longest_Substring_Without_Repeating_Characters(string str){
	//sliding window+ hashtable
	return ;
}


void longest_palin_substring_DP(string s){
	//can be done using dp
	//	Using DP:
	//manually fill matrix for 1 and 2 length palins
//	abcghghcxyz
cout<<s<<endl;
	bool dp[s.size()][s.size()];
	int max_len = 1;
	string ans_str="a";
	for(int i=0;i<s.size();i++){
		for(int j=0;j<s.size();j++){
			dp[i][j]=0;
		}
	}
	//each char is a palin with itself
	for(int i=0;i<s.size();i++){
		dp[i][i]=1;
	}
	//for len 2:
	for(int i=0;i<s.size()-1;i++){
		if(s[i]==s[i+1]){
			dp[i][i+1]=1;
			max_len = 2;
			ans_str = s.substr(i,2);
			cout<<ans_str<<endl;
		}
			
	}
	//for len 3 and more:
	for(int len =3;len<=s.size();len++){
		for(int start =0;start<s.size()-len+1;start++){
			int end = start+len-1;
			//for example: to check for start = 0 and end = 4 in axyxa check if start = 1 and end = 3 is palin or not
			if(dp[start+1][end-1]==1 && s[start]==s[end]){
				dp[start][end]=1;
				if(len>max_len){
					max_len = len;
					ans_str = s.substr(start,max_len);
					cout<<ans_str<<endl;
				}
			} 
		}
	}
	
	cout<<max_len<<" "<<ans_str<<endl;
	for(int i=0;i<s.size();i++){
		for(int j=0;j<s.size();j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
}

int lpsc_helper(string s, int left, int right){
	while(s[left]==s[right] && left>=0 && right<s.length()){
		left--;
		right++;
	}
	return right-left-1;
//	ABABA
}
void longest_palin_substring_centres(string s){

	//using expansion around centre APProach:
	//	asdfgfklmlkfg n = 13- odd centre can be any character(13), any space between characters(12)
	//total centres = 2n-1
	int start =0;
	int end =0;
	int curr_len =0;
	string ans="";
	for(int i =0;i<s.size();i++){
		int len1 = lpsc_helper(s,i,i);//centre is the character itself
		int len2 = lpsc_helper(s,i,i+1);//call at stick space between 2 chars
		int temp_len = max(len1, len2);
		if(temp_len>end-start){
			start = i - (temp_len-1)/2;
			end = i+temp_len/2;
//			ans = s.substr(i-(temp_len-1)/2,temp_len);
			curr_len = temp_len;
			
		}
	}
	ans = s.substr(start, curr_len);
	cout<<ans<<endl;
}
int main(){		
	string s;
//	cin>>s;
//	s= "abcghgh";
	int n = s.length();
//	longest_common_substring("xyzahhib","abchhi");
//	longest_common_substring(s1,s2);
//	longest_common_substring(s1,"abchhi");
//	n = 7;
//	lps(s,n);
	string arr[]={"abc","xyzabc","demtor","pritor","prefix","suffix"};
//	shortest_common_superseq(arr);
//	Longest_Substring_Without_Repeating_Characters(s);
s = "abcghghcxyz";
longest_palin_substring_DP(s);
longest_palin_substring_centres(s);
}
