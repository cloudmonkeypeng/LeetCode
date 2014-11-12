class solution{

public:

	int lcs(char *str1, char *str2){

		int temp,str1_start,str2_start;

		//建立索引
		int index = 0;
		
		//计算遍历长度
		int len1 = strlen(str1);
		int len2 = strlen(str2);
		int len = len1 + len2;
		
		int max = 0;
		int current_max = 0;

		for(int i = 0 ; i < len ; i++){

			str1_start = str2_start = 0;
			
			if(i < len1)
				str1_start = len1 - i;    
			else
				str2_start = i - len1;
			
			current_max = 0;
			
			for(index = 0 ; ( str1_start + index < len1 ) && ( str2_start + index < len2 ); index++ )
			{
				if(str1[str1_start+index]==str2[str2_start+index])
					current_max++;
				else     
				{
					//遇到不相等跳出循环
					if(current_max > max)
					{
						max = current_max;
						temp = str1_start+index-1;      
					}
					current_max = 0;
				}
			}

			if(current_max > max)
			{
				max = current_max;
				temp = str1_start+index-1;
			}
		}


		return max;
	}
};
