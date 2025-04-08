int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int gas_total = 0;
    int cost_total = 0;
    int fuel = 0;
    int result = 0;

    for(int i = 0; i < gasSize; i++){
        gas_total += gas[i];
        cost_total += cost[i];

        fuel += gas[i] - cost[i];

        if(fuel < 0){
            result = i + 1;
            fuel = 0;
        }
    }

    if(gas_total < cost_total)
        return -1;
    
    return result;
}
