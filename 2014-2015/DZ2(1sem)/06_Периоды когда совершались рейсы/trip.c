#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

struct Ttime {
	int year;
	int month;
	int day;
};

struct Trip {
	struct Ttime start;
	struct Ttime finish;
};

int greater(struct Ttime tr1, struct Ttime tr2) {
	return tr1.year > tr2.year ||
		tr1.year == tr2.year && tr1.month > tr2.month ||
		tr1.year == tr2.year && tr1.month == tr2.month && tr1.day > tr2.day;
}

struct Ttime neighbor(struct Ttime tr1) {
	time_t rawtime;  
	struct tm * stTimeInfo;   
	time ( &rawtime );  
	stTimeInfo = localtime ( &rawtime );  
	stTimeInfo->tm_year = tr1.year - 1900;  
	stTimeInfo->tm_mon = tr1.month - 1;  
	stTimeInfo->tm_mday = tr1.day-1;  
	mktime ( stTimeInfo );  
	tr1.year = stTimeInfo->tm_year+1900;
	tr1.month = stTimeInfo->tm_mon+1;
	tr1.day = stTimeInfo->tm_mday;
	return tr1;
}

void selSort(struct Trip *array, int n) {
	int i;
	for ( i = 0 ; i < ( n - 1 ) ; i++ ) {
		int pos = i;
		int d;
		for ( d = i + 1 ; d < n ; d++ )
			if (greater(array[pos].start, array[d].start)) pos = d;
		if ( pos != i ) {
			struct Trip swap = array[i];
			array[i] = array[pos];
			array[pos] = swap;
		}
	}
}

void print(struct Trip data) {
	printf("%d-",data.start.year);
	printf("%02d-",data.start.month);
	printf("%02d ",data.start.day);
	printf("%d-",data.finish.year);
	printf("%02d-",data.finish.month);
	printf("%02d\n",data.finish.day);
}

int main(int argc, char** argv) {
	if ( argc < 2 ) {
		printf("The first argument have to be a name of file\n");
		return 0;
	} else {
		FILE *file;
		file = fopen(argv[1],"rt");
		if ( !file ) {
			printf("File doesn't exist\n");
			return 0;
		}
		clock_t begin, end;
		double time_spent;
		begin = clock();
		int size = 2;
		struct Trip *trips = (struct Trip *) calloc(size, sizeof(struct Trip));
		int i = 0;
		while (fscanf(file,"%d-%d-%d %d-%d-%d", 
			&trips[i].start.year, &trips[i].start.month, &trips[i].start.day,
			&trips[i].finish.year, &trips[i].finish.month, &trips[i].finish.day) != EOF) {
			i++;
			if ( i == size - 1) {
				size *= 2;
				trips = (struct Trip *) realloc (trips, size* sizeof(struct Trip));
			}
		}
		int n = i;

		selSort(&trips[0],n);

		struct Trip current = trips[0];
		for (i = 1; i < n; i++) {
			if (!greater(neighbor(trips[i].start), current.finish)) {
				if (greater(trips[i].finish, current.finish))
					current.finish = trips[i].finish;
			} else {
				print(current);
				current = trips[i];
			}	
		}
		print(current);
		free(trips);
		fclose(file);
		end = clock();
		time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		printf("Time of program: %f\n", time_spent);
		return 0;
	}
}