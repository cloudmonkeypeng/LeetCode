int maximalRectangle(vector<vector<char> > &matrix) {
	
	if(matrix.empty()) return 0;

	const int height = matrix.size();

	const int width = matrix[0].size();

	int maxArea = 0;

	vector<int> L(width,0);

	vector<int> H(width,0);

	vector<int> R(width,width);

	for(int m=0;m<height;m++){

		int left = 0;

		for(int n=0;n<width;n++){

			if(matrix[m][n]=='1'){

				H[n]++;

				L[n] = max(L[n],left);
			
			}else{
				left = n+1;

				H[n]=0; L[n]=0; R[n]=width;
			}

		}

		int right = 0;

		for(int n=width-1;n>=0;n--){

			if(matrix[m][n]=='1'){
				R[n] = min(right,R[n]);
				maxArea = max(maxArea,H[n]*(R[n]-L[n]));
			}else{
				right = n;
			}

		}

	}

	return maxArea;
}