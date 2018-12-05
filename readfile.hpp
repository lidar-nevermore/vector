#include <vector>
#include <ctime>
#include <cstdio>
static char *line;
static int max_line_len;
static double taketime()
{
	return (double)(clock()) / CLOCKS_PER_SEC;
}
static char *readline(FILE *input)
{
	int len;
	if (fgets(line, max_line_len, input) == NULL)
		return NULL;
	while (strrchr(line, '\n') == NULL)
	{
		max_line_len *= 2;
		line = (char *)realloc(line, max_line_len);
		len = (int)strlen(line);
		if (fgets(line + len, max_line_len - len, input) == NULL)
			break;
	}
	len = (int)strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	return line;
}

static void readfile(const char *filename, std::vector<std::vector<double>> &vec)
{
	FILE *fp;	
	int num_of_records, num_elements,i;
	char *endptr, *val, *next_val;
	double *line_data,  value;	

	double start_time = taketime();//taketime
	fopen_s(&fp, filename, "r");
	if (fp == NULL)
	{
		printf("can't open input file %s\n", filename);
		return;
	}
	num_of_records = 0;
	max_line_len = 1024;
	line = (char *)malloc(max_line_len * sizeof(char));

	while (readline(fp) != NULL)
	{
		num_of_records++;
	}
	rewind(fp);

	vec.reserve(num_of_records);
	line_data = (double *)malloc(max_line_len / 2 * sizeof(double));

	for (i = 0; i < num_of_records; i++)
	{		
		readline(fp);
		val = strtok_s(line, " ",&next_val); // value1
		if (val == NULL)
		{
			printf("Empty line at line %d\n", i + 1);			
			return;
		}
		line_data[0] = strtod(val, &endptr);// convert to double
		num_elements = 1;
		while (1)
		{
			val = strtok_s(NULL, " ", &next_val); // value 2:end
			if (val == NULL)
				break;
			errno = 0;
			value = strtod(val, &endptr);// convert to double
			if (endptr == val || errno != 0 || *endptr != '\0')
			{
				printf("Wrong input format at line %d,column %d\n", num_of_records + 1, num_elements + 1);
				return;
			}
			line_data[num_elements] = value;
			num_elements++;
		}
		vec.push_back(std::move(std::vector<double>(line_data, line_data + num_elements)));
	}	
	free(line);
	free(line_data);
	printf("total time: %g sec for %d records\n", taketime() - start_time, num_of_records);//taketime
	fclose(fp);
	return;
}
