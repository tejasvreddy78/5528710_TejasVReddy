int truckTour(int petrolpumps_rows, int petrolpumps_columns, int** petrolpumps) {
    long long total = 0, balance = 0;
    int start = 0;

    for (int i = 0; i < petrolpumps_rows; i++){
        int petrol = petrolpumps[i][0];
        int distance = petrolpumps[i][1];
        total += (petrol - distance);
        balance += (petrol - distance);

        if (balance < 0){
            start = i + 1;
            balance = 0;
        }
    }
    if (total >= 0) return start;
    else return -1;
}
