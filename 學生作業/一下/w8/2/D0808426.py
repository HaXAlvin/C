import json


def analyze(data):
    """Structures:
        Output:
        [
            {
                "發病日": "1234/01",
                "新北市": 1
            },
            {
                ...
            }
        ]

        Stored as:
        {
            "1234/01": {
                "新北市": 1
            },
            ...
        }
    """

    sick_table = {}  # A table to store loaded data
    for case in data:
        # Extract Data
        month = '/'.join(case['發病日'].split('/')[:2])  # Remove days
        city = case['居住縣市']

        # Check if the first layer key (xxxx/xx) exists
        if month not in sick_table.keys():
            sick_table[month] = {city: 1}
        else:
            # Check if the second layer key (xx縣市) exists
            if city in sick_table[month].keys():
                sick_table[month][city] += 1
            else:
                sick_table[month][city] = 1
    # Convert 'Stored' structure -> 'Output' structure
    # Dictionary unpacking operators (**) (used for merging dicts) relies on Python 3.5+
    # Dictionary ordering (used for sorting) relies on Python 3.6+
    return list({'發病日': x[0], **x[1]} for x in sick_table.items())


def main():
    # Load source data
    input_file = 'Dengue_Daily.json'
    output_file = 'Result.json'
    with open(input_file, 'r', encoding='utf-8-sig') as f:
        data = json.load(f)
    # Analyze data
    data_processed = analyze(data)

    # Write result
    # print(json.dumps(data_processed, indent=2, ensure_ascii=False))
    with open(output_file, 'w', encoding='utf-8-sig') as f:
        json.dump(data_processed, f, indent=2,
                  ensure_ascii=False)  # ensure_ascii is disabled to display unescaped Chinese


if __name__ == '__main__':
    main()
