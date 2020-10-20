int minCostToMoveChips(int* position, int positionSize){
    int odd = 0, even = 0;
	for (int i = 0; i < positionSize; i++) {
		if (position[i] % 2 == 0) {
			even++;
		} else if (position[i] % 2 != 0) {
			odd++;
		}
	}

    return odd > even ? even : odd;
}