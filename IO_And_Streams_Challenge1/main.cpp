// Section 19
// Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

void ruler()
{
    std::cout << "1234567890123456789012345678901234567890123456789012345678901234567890" << std::endl;
}

int main()
{
    Tours tours
        { "Tour Ticket Prices from Miami",
            {
                {
                    "Colombia", { 
                        { "Bogota", 8778000, 400.98 },
                        { "Cali", 2401000, 424.12 },
                        { "Medellin", 2464000, 350.98 },
                        { "Cartagena", 972000, 345.34 } 
                    },
                },
                {
                    "Brazil", { 
                        { "Rio De Janiero", 13500000, 567.45 },
                        { "Sao Paulo", 11310000, 975.45 },
                        { "Salvador", 18234000, 855.99 }
                    },
                },
                {
                    "Chile", { 
                        { "Valdivia", 260000, 569.12 }, 
                        { "Santiago", 7040000, 520.00 }
                },
            },
                { "Argentina", { 
                    { "Buenos Aires", 3010000, 723.77 } 
                } 
            },
        }
    };

    // Fomat display
    const int total_width {70};
    const int country_field {20};
    const int city_field {20};
    const int population_field {15};
    const int cost_field {15};

    ruler();

    // Title
    int title_length = tours.title.length();
    std::cout << std::setw((total_width - title_length)/2) << "" << tours.title << std::endl;

    // Columns
    std::cout << std::setw(country_field) << std::left << "Country"
                << std::setw(city_field) << std::left << "City"
                << std::setw(population_field) << std::right << "Population"
                << std::setw(cost_field) << std::right << "Price"
                << std::endl;

    // Line separator
    std::cout << std::setw(total_width)
                << std::setfill('-')
                << ""
                << std::endl;

    // Reset setfill
    std::cout << std::setfill(' ');
    std::cout << std::setprecision(2) << std::fixed;

    for(const auto& country : tours.countries) {   // loop through the countries
        std::cout << std::setw(country_field) << std::left << country.name << std::endl;
        for(const auto& city : country.cities) {       // loop through the cities for each country
            std::cout << std::setw(country_field) << std::left << ""
                        << std::setw(city_field) << std::left << city.name
                        << std::setw(population_field) << std::right << city.population
                        << std::setw(cost_field) << std::right << city.cost
                        << std::endl;
        }
    }

    std::cout << std::endl << std::endl;
    return 0;
}