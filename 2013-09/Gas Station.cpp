 int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
 	
 	int total=0;

 	int index=0;

 	int sum = 0;

 	for(int i=0;i<gas.size();i++){

 		sum += gas[i] - cost[i];

 		total += gas[i] - cost[i];

 		if(sum<0){

 			index = i;

 			sum = 0;

 		}

 	}

 	if(total>=0){
 		return index+1;
 	}else{
 		return -1;
 	}

 }