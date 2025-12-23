import re
from datetime import datetime

# Define custom exceptions
class InvalidDateFormat(Exception):
    pass

class InvalidMonthName(Exception):
    pass

# Helper function to map month names to numbers
def month_name_to_number(month_name):
    months = {
        "january": 1, "february": 2, "march": 3, "april": 4,
        "may": 5, "june": 6, "july": 7, "august": 8,
        "september": 9, "october": 10, "november": 11, "december": 12
    }
    month_name = month_name.lower()
    if month_name not in months:
        raise InvalidMonthName("Invalid month name")
    return months[month_name]

# Function to extract date and time components
def extract_datetime(dateTimeString):
    try:
        # Regex patterns for various formats
        pattern1 = r'(\d{4})[-/](\d{2})[-/](\d{2}) (\d{2}):(\d{2}):(\d{2})'  # YYYY-MM-DD HH:mm:ss or YYYY/MM/DD HH:mm:ss
        pattern2 = r'(\d{2}) (\w+) (\d{4}) (\d{2}):(\d{2}):(\d{2})'            # DD Month YYYY HH:mm:ss

        # Match for the first pattern
        match1 = re.match(pattern1, dateTimeString)
        if match1:
            year, month, day, hour, minute, second = map(int, match1.groups())
        else:
            # Match for the second pattern with the month name
            match2 = re.match(pattern2, dateTimeString)
            if match2:
                day, month_name, year, hour, minute, second = match2.groups()
                day, year, hour, minute, second = map(int, [day, year, hour, minute, second])
                month = month_name_to_number(month_name)
            else:
                raise InvalidDateFormat("Invalid date and time format")

        # Validate date and time using datetime module
        datetime(year, month, day, hour, minute, second)

        # Return the formatted result
        return f"Year: {year}, Month: {month}, Day: {day}, Hour: {hour}, Minute: {minute}, Second: {second}"

    except ValueError:
        raise InvalidDateFormat("Invalid date or time format")

# Example usage:
try:
    result = extract_datetime("2023-09-29 14:30:45")
    print(result)  # Expected: Year: 2023, Month: 9, Day: 29, Hour: 14, Minute: 30, Second: 45
except (InvalidDateFormat, InvalidMonthName) as e:
    print(str(e))

      