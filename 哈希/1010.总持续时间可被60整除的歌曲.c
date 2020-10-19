int numPairsDivisibleBy60(int* time, int timeSize){
	
	int count = 0;
	int store[60] = {0};//hash表
	
	for(int i = 0; i < timeSize; i++)
	{
		time[i] %= 60;
		store[time[i]]++;
	}
	
	for(int i = 0; i < timeSize - 1; i++)
	{
		store[time[i]]--;
		if(time[i] == 0)
		{
			count += store[time[i]];
		}
		else
		{
			count += store[60 - time[i]];
		}
	}
	
	return count;
}
