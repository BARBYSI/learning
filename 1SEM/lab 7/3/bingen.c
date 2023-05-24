int binary(int n){
    FILE *binf = fopen("numbers.bin", "wb");
    int bnums[2] = {1, -1};
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        fprintf(binf, "%d ", rand() % 100 * bnums[rand() % 2]);
    }
    fclose(binf);
}