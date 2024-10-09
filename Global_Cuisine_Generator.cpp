//Layla Rateb
//Utopia Project
//CS 211 Lab 
/*Updated Project Proposal-
In a society where positive changes can be made with the flick of a switch, one significant
change I would want to see is the eradication of food waste and the promotion of cultural diversity. My role in effecting this change
would be to develop and maintain a C++ program that plays a role in allowing users to explore different dishes from various countries around 
world, while using ingredients that they may have leftover at home or an excess amount of instead of throwing it out or allowing it to expire.
This project will also help users decide what to cook when they want to explore new options. The user must input at least 2 food items that are 
seperated with a space but no commas and food items that consist of two words must be paired together such as bellpeppers and coconutmilk. After
inputting ingredients, if is a country that has any of the inputted ingredients it will be displayed to the screen along with a dish from that country 
and a message regarding food waste. If there is more than one country that has a dish with the users inputted ingredients then the user will have the 
option to choose which country they would like to cook a dish from by inputting the listed number, which will then present the user with a dish from that 
country along with a message regarding food waste. This project implements topics from CS211 lab and lecture such as vectors, struct, and 
function.
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <sstream>

struct Country { //implement a strcuture named 'Country' which will reprsent info about a country's dish

public: //public - so the memebers of the struct will be accesible from outside of the struct 
   
    std::string name;//store name of country
    std::vector<std::string> ingredients;//store the ingredients of the countries dish
    std::string dishName; //create a new member variable to store the dish name
};

//Make a function to check if a country has all the user ingredients
/*function created to receive two parameters, one is a vector which contains the user's specified 
ingredients and a Country object that represents the  ingredients that are needed for a particular
country's dish. purpose of function - to see if all of the user's ingredients are present in the set of 
ingredients required for the country's dish. function returns a boolean value, which will let the 
program know if the user has all of the ingredients for the country’s recipe*/
bool hasIngredients(const std::vector<std::string>& userIngredients, const Country& country) {
    std::vector<std::string> countryIngredients = country.ingredients; //this vector contains the original list of ingredients for a specific country's dish.
    std::sort(countryIngredients.begin(), countryIngredients.end());//this std::sort will help to SORT the elements that are in the vector 'countryIngredients'
    //need to implement sorting to compare it properly 
    // The std::set_intersection algorithm requires sorted ranges
    // It finds the common elements between two sorted ranges and stores them in the result vector
    std::vector<std::string> result;
    std::set_intersection( //can be used to find the common elements between the user's ingredients and the country's ingredients

        userIngredients.begin(), userIngredients.end(), //reprsents the range of useer Ingredients from the beg until the end of the vector
        countryIngredients.begin(), countryIngredients.end(), //reprsents the range of country Ingredients from the countryIngredients vector
        std::back_inserter(result) //iterator will allow elemngts to be inserted to the END of the result vector 
    );
    //If the size of the result vector is equal to the size of userIngredients, all userIngredients are present in the country's ingredients
    return result.size() == userIngredients.size();
}

int main() { //start of main function 

//Long list of countries will be presented along with a dish and ingredients that go into that dish
//The 'Country' Structure will be used to reprsent the specefic countries dish. 
    
    Country afghanistan; //This creates an instance of the country's sctructure named 'afghanistan'
    afghanistan.name = "Afghanistan"; //sets the name of the country to Afghanistan which will be displayed to the terminal if the user has its ingredients
    //Ingredients added to the vector 'ingredients' for the Afghan dish known as "Bolani"
    afghanistan.ingredients.push_back("flour"); //push_back function is used on the vector 'ingredients', its adding the ingredient to the vector
    afghanistan.ingredients.push_back("spinach");
    afghanistan.dishName = "Bolani"; //sets the name of the dish to "Bolani" which will be displayed if this country is matched with the users input or chosen by the user
    //The same idea and vector is used for the remaining countries and their ingredients 
    Country albania;
    albania.name = "Albania";
    albania.ingredients.push_back("lamb");
    albania.ingredients.push_back("yogurt");
    albania.ingredients.push_back("eggs");
    albania.ingredients.push_back("flour");
    albania.dishName = "Tave Kosi";

    Country algeria;
    algeria.name = "Algeria";
    algeria.ingredients.push_back("couscous");
    algeria.ingredients.push_back("chicken");
    algeria.ingredients.push_back("chickpeas");
    algeria.ingredients.push_back("rice");
    algeria.ingredients.push_back("carrot");
    algeria.ingredients.push_back("zucchini");
    algeria.dishName = "Algerian Couscous";

    Country argentina;
    argentina.name = "Argentina";
    argentina.ingredients.push_back("beef");
    argentina.ingredients.push_back("breadcrumbs");
    argentina.ingredients.push_back("egg");
    argentina.ingredients.push_back("flour");
    argentina.dishName = "Milanesa";

    Country armenia;
    armenia.name = "Armenia";
    armenia.ingredients.push_back("bulgurwheat");
    armenia.ingredients.push_back("oliveoil");
    armenia.ingredients.push_back("tomatoes");
    armenia.ingredients.push_back("lemonjuice");
    armenia.ingredients.push_back("cucumber");
    armenia.ingredients.push_back("mintleaves");
    armenia.ingredients.push_back("onions");
    armenia.dishName = "Tabouli Salad";

    Country austria;
    austria.name = "Austria";
    austria.ingredients.push_back("beef");
    austria.ingredients.push_back("potato");
    austria.ingredients.push_back("butter");
    austria.ingredients.push_back("onion");
    austria.ingredients.push_back("egg");
    austria.dishName = "Grostl";

    Country azerbaijan;
    azerbaijan.name = "Azerbaijan";
    azerbaijan.ingredients.push_back("rice");
    azerbaijan.ingredients.push_back("meat");
    azerbaijan.ingredients.push_back("driedfruits");
    azerbaijan.dishName = "Shah Plov";

    Country bahrain;
    bahrain.name = "Bahrain";
    bahrain.ingredients.push_back("rice");
    bahrain.ingredients.push_back("chicken");
    bahrain.ingredients.push_back("onions");
    bahrain.ingredients.push_back("garlic");
    bahrain.ingredients.push_back("cardamom");
    bahrain.ingredients.push_back("tomatoes");
    bahrain.dishName = "Chicken Machboos";

    Country bosniaHerzegovina;
    bosniaHerzegovina.name = "Bosnia & Herzegovina";
    bosniaHerzegovina.ingredients.push_back("beans");
    bosniaHerzegovina.ingredients.push_back("bellpepper");
    bosniaHerzegovina.ingredients.push_back("onions");
    bosniaHerzegovina.ingredients.push_back("tomatoepaste");
    bosniaHerzegovina.ingredients.push_back("flour");
    bosniaHerzegovina.ingredients.push_back("beef");
    bosniaHerzegovina.ingredients.push_back("carrot");
    bosniaHerzegovina.dishName = "Grah";

    Country bulgaria;
    bulgaria.name = "Bulgaria";
    bulgaria.ingredients.push_back("tomatoes");
    bulgaria.ingredients.push_back("cucumbers");
    bulgaria.ingredients.push_back("fetacheese");
    bulgaria.ingredients.push_back("olives");
    bulgaria.dishName = "Shopska";

    Country cambodia;
    cambodia.name = "Cambodia";
    cambodia.ingredients.push_back("codfish");
    cambodia.ingredients.push_back("coconutmilk");
    cambodia.ingredients.push_back("lemongrass");
    cambodia.dishName = "Fish Amok";

    Country chile;
    chile.name = "Chile";
    chile.ingredients.push_back("corn");
    chile.ingredients.push_back("groundbeef");
    chile.ingredients.push_back("onions");
    chile.ingredients.push_back("milk");
    chile.ingredients.push_back("flour");
    chile.dishName = "Pastel De Choclo";


    Country colombia;
    colombia.name = "Colombia";
    colombia.ingredients.push_back("rice");
    colombia.ingredients.push_back("beans");
    colombia.ingredients.push_back("plantains");
    colombia.ingredients.push_back("beef");
    colombia.ingredients.push_back("avacado");
    colombia.ingredients.push_back("egg");
    colombia.dishName = "Bandeja Paisa";

    Country costaRica;
    costaRica.name = "Costa Rica";
    costaRica.ingredients.push_back("rice");
    costaRica.ingredients.push_back("beans");
    costaRica.ingredients.push_back("onions");
    costaRica.dishName = "Gallo Pinto";

    Country cuba;
    cuba.name = "Cuba";
    cuba.ingredients.push_back("rice");
    cuba.ingredients.push_back("beans");
    cuba.ingredients.push_back("beef");
    cuba.ingredients.push_back("tomatoesauce");
    cuba.dishName = "Ropa Vieja";

    Country croatia;
    croatia.name = "Croatia";
    croatia.ingredients.push_back("lamb");
    croatia.ingredients.push_back("potatoes");
    croatia.ingredients.push_back("carrot");
    croatia.ingredients.push_back("onion");
    croatia.ingredients.push_back("garlic");
    croatia.dishName = "Peka";

    Country dominicanRepublic;
    dominicanRepublic.name = "Dominican Republic";
    dominicanRepublic.ingredients.push_back("flour");
    dominicanRepublic.ingredients.push_back("groundbeef");
    dominicanRepublic.ingredients.push_back("onion");
    dominicanRepublic.ingredients.push_back("bellpeppers");
    dominicanRepublic.ingredients.push_back("egg");
    dominicanRepublic.ingredients.push_back("olives");
    dominicanRepublic.dishName = "Empanadas";

    Country egypt;
    egypt.name = "Egypt";
    egypt.ingredients.push_back("rice");
    egypt.ingredients.push_back("lentils");
    egypt.ingredients.push_back("macaroni");
    egypt.ingredients.push_back("garlic");
    egypt.ingredients.push_back("onion");
    egypt.ingredients.push_back("tomatoesauce");
    egypt.dishName = "Koshary";

    Country estonia;
    estonia.name = "Estonia";
    estonia.ingredients.push_back("carrot");
    estonia.ingredients.push_back("potatoes");
    estonia.ingredients.push_back("eggs");
    estonia.ingredients.push_back("mayonnaise");
    estonia.ingredients.push_back("buttermilk");
    estonia.dishName = "Kartulisalat";

    Country equatorialGuinea;
    equatorialGuinea.name = "Equatorial Guinea";
    equatorialGuinea.ingredients.push_back("corn");
    equatorialGuinea.ingredients.push_back("beans");
    equatorialGuinea.ingredients.push_back("tomatoe");
    equatorialGuinea.ingredients.push_back("okra");
    equatorialGuinea.dishName = "Succotash";

    Country france;
    france.name = "France";
    france.ingredients.push_back("beef");
    france.ingredients.push_back("Gruyerecheese");
    france.ingredients.push_back("potatoes");
    france.ingredients.push_back("onions");
    france.dishName = "Hachis Parmentier";

    Country gambia; 
    gambia.name = "Gambia";
    gambia.ingredients.push_back("peanuts");
    gambia.ingredients.push_back("tomatoes");
    gambia.ingredients.push_back("onions");
    gambia.ingredients.push_back("chickpeas");
    gambia.ingredients.push_back("peanutbutter");
    gambia.ingredients.push_back("sweetpotatoes");
    gambia.ingredients.push_back("tomatoepaste");
    gambia.dishName = "Domoda";

    Country greece;
    greece.name = "Greece";
    greece.ingredients.push_back("eggplant");
    greece.ingredients.push_back("potatoes");
    greece.ingredients.push_back("beef");
    greece.dishName = "Moussaka";

    Country jamaica;
    jamaica.name = "Jamaica";
    jamaica.ingredients.push_back("callaloo");
    jamaica.ingredients.push_back("garlic");
    jamaica.ingredients.push_back("onions");
    jamaica.ingredients.push_back("tomatoes");
    jamaica.dishName = "Callaloo";

    Country jordan;
    jordan.name = "Jordan";
    jordan.ingredients.push_back("rice");
    jordan.ingredients.push_back("black lentils");
    jordan.ingredients.push_back("onions");
    jordan.dishName = "Mujadara";
    
    Country kenya;
    kenya.name = "Kenya";
    kenya.ingredients.push_back("corn");
    kenya.ingredients.push_back("peas");
    kenya.ingredients.push_back("potatoes");
    kenya.dishName = "Irio";

    Country india;
    india.name = "India";
    india.ingredients.push_back("peas");
    india.ingredients.push_back("ginger");
    india.ingredients.push_back("onions");
    india.ingredients.push_back("cilantro");
    india.ingredients.push_back("potatoes");
    india.ingredients.push_back("flour");
    india.dishName = "Samosa";

    Country indonesia;
    indonesia.name = "Indonesia";
    indonesia.ingredients.push_back("corn");
    indonesia.ingredients.push_back("tomatoes");
    indonesia.ingredients.push_back("zucchini");
    indonesia.ingredients.push_back("kale");
    indonesia.ingredients.push_back("cabbage");
    indonesia.ingredients.push_back("greenbeans");
    indonesia.dishName = "Sayur Asem";

    Country italy;
    italy.name = "Italy";
    italy.ingredients.push_back("tomatoes");
    italy.ingredients.push_back("flour");
    italy.ingredients.push_back("cheese");
    italy.dishName = "Pizza";

    Country iran;
    iran.name = "Iran";
    iran.ingredients.push_back("rice");
    iran.ingredients.push_back("chicken");
    iran.ingredients.push_back("yogurt");
    iran.ingredients.push_back("saffron");
    iran.ingredients.push_back("raisins");
    iran.dishName = "Tahchin"; 

    Country iraq;
    iraq.name = "Iraq";
    iraq.ingredients.push_back("okra");
    iraq.ingredients.push_back("tomatoepaste");
    iraq.ingredients.push_back("greenbeans");
    iraq.ingredients.push_back("garlic");
    iraq.ingredients.push_back("tomatoe");
    iraq.ingredients.push_back("onion");
    iraq.dishName = "Maraq Baamiye";
    
    Country lebanon;
    lebanon.name = "Lebanon";
    lebanon.ingredients.push_back("grapeleaves");
    lebanon.ingredients.push_back("rice");
    lebanon.ingredients.push_back("tomatoe");
    lebanon.ingredients.push_back("potatoe");
    lebanon.ingredients.push_back("onion");
    lebanon.ingredients.push_back("groundbeef");
    lebanon.dishName = "Dolma";

    Country libya;
    libya.name = "Libya";
    libya.ingredients.push_back("onion");
    libya.ingredients.push_back("tomatoe");
    libya.ingredients.push_back("egg");
    libya.ingredients.push_back("cilantro");
    libya.ingredients.push_back("parsley");
    libya.dishName = "Shakshuka";

    Country mexico;
    mexico.name = "Mexico";
    mexico.ingredients.push_back("flourtortillas");
    mexico.ingredients.push_back("groundbeef");
    mexico.ingredients.push_back("onion");
    mexico.ingredients.push_back("lettuce");
    mexico.ingredients.push_back("cheese");
    mexico.ingredients.push_back("tomatoe");
    mexico.ingredients.push_back("corn");
    mexico.ingredients.push_back("beans");
    mexico.dishName = "Beef Quesadilla";

    Country morocco;
    morocco.name = "Morocco";
    morocco.ingredients.push_back("couscous");
    morocco.ingredients.push_back("lamb");
    morocco.ingredients.push_back("bellpeppers");
    morocco.ingredients.push_back("raisins");
    morocco.ingredients.push_back("lemon");
    morocco.ingredients.push_back("onion");
    morocco.ingredients.push_back("carrots");
    morocco.ingredients.push_back("garlic");
    morocco.ingredients.push_back("chickpeas");
    morocco.ingredients.push_back("cilantro");
    morocco.dishName = "Moroccan Couscous";

    Country nepal;
    nepal.name = "Nepal";
    nepal.ingredients.push_back("onion");
    nepal.ingredients.push_back("cilantro");
    nepal.ingredients.push_back("rice");
    nepal.ingredients.push_back("lentils");
    nepal.ingredients.push_back("curry");
    nepal.ingredients.push_back("lime");
    nepal.dishName = "Dal Bhaath";

    Country puertoRico;
    puertoRico.name = "Puerto Rico";
    puertoRico.ingredients.push_back("potatoes");
    puertoRico.ingredients.push_back("groundbeef");
    puertoRico.ingredients.push_back("onions");
    puertoRico.ingredients.push_back("cheese");
    puertoRico.ingredients.push_back("egg");
    puertoRico.dishName = "Rellenos De Papa";

    Country philippines;
    philippines.name = "Philippines";
    philippines.ingredients.push_back("purple yam");
    philippines.ingredients.push_back("coconutmilk");
    philippines.ingredients.push_back("condensedmilk");
    philippines.ingredients.push_back("butter");
    philippines.ingredients.push_back("sugar");
    philippines.dishName = "Ube Halaya";

    Country russia;
    russia.name = "Russia";
    russia.ingredients.push_back("beets");
    russia.ingredients.push_back("carrots");
    russia.ingredients.push_back("potatoes");
    russia.ingredients.push_back("garlic");
    russia.ingredients.push_back("cabbage");
    russia.ingredients.push_back("onions");
    russia.ingredients.push_back("sourcream");
    russia.dishName = "Borscht";

    Country saudiArabia;
    saudiArabia.name = "Saudi Arabia";
    saudiArabia.ingredients.push_back("rice");
    saudiArabia.ingredients.push_back("chicken");
    saudiArabia.ingredients.push_back("onions");
    saudiArabia.ingredients.push_back("tomatoes");
    saudiArabia.ingredients.push_back("raisins");
    saudiArabia.ingredients.push_back("saffron");
    saudiArabia.dishName = "Chicken Kabsa";

    Country serbia;
    serbia.name = "Serbia";
    serbia.ingredients.push_back("rice");
    serbia.ingredients.push_back("bellpeppers");
    serbia.ingredients.push_back("groundbeef");
    serbia.ingredients.push_back("tomatopaste");
    serbia.ingredients.push_back("onions");
    serbia.dishName = "Punjene Paprike";

    Country somalia;
    somalia.name = "Somalia";
    somalia.ingredients.push_back("rice");
    somalia.ingredients.push_back("onions");
    somalia.ingredients.push_back("chicken");
    somalia.ingredients.push_back("saffron");
    somalia.ingredients.push_back("raisins");
    somalia.dishName = "Bariis Iskukaris";

    Country spain;
    spain.name = "Spain";
    spain.ingredients.push_back("rice");
    spain.ingredients.push_back("saffron");
    spain.ingredients.push_back("bellpeppers");
    spain.ingredients.push_back("tomatoe");
    spain.ingredients.push_back("peas");
    spain.ingredients.push_back("chicken");
    spain.dishName = "Paella";

    Country Syria;
    Syria.name = "Syria";
    Syria.ingredients.push_back("groundbeef");
    Syria.ingredients.push_back("bulgurwheat");
    Syria.ingredients.push_back("onion");
    Syria.dishName = "Kibbeh";

    Country venezuela;
    venezuela.name = "Venezuela";
    venezuela.ingredients.push_back("rice");
    venezuela.ingredients.push_back("beef");
    venezuela.ingredients.push_back("plantains");
    venezuela.ingredients.push_back("beans");
    venezuela.dishName = "Pabellon Criollo";

    Country yemen;
    yemen.name = "Yemen";
    yemen.ingredients.push_back("rice");
    yemen.ingredients.push_back("chicken");
    yemen.ingredients.push_back("onion");
    yemen.ingredients.push_back("saffron");
    yemen.ingredients.push_back("raisins");
    yemen.dishName = "Mandi";
    //create a vector that will store the country objects 
    std::vector<Country> countries;
    //add country objects to vector 
    countries.push_back(afghanistan);
    countries.push_back(albania);
    countries.push_back(algeria);
    countries.push_back(argentina);
    countries.push_back(armenia);
    countries.push_back(austria);
    countries.push_back(azerbaijan);
    countries.push_back(bahrain);
    countries.push_back(bosniaHerzegovina);
    countries.push_back(bulgaria);
    countries.push_back(cambodia);
    countries.push_back(chile);
    countries.push_back(colombia);
    countries.push_back(costaRica);
    countries.push_back(cuba);
    countries.push_back(dominicanRepublic);
    countries.push_back(croatia);
    countries.push_back(egypt);
    countries.push_back(estonia);
    countries.push_back(equatorialGuinea);
    countries.push_back(gambia);
    countries.push_back(france);
    countries.push_back(greece);
    countries.push_back(jamaica);
    countries.push_back(jordan);
    countries.push_back(kenya);
    countries.push_back(india);
    countries.push_back(indonesia);
    countries.push_back(italy);
    countries.push_back(iran);
    countries.push_back(iraq);
    countries.push_back(lebanon);
    countries.push_back(libya);
    countries.push_back(mexico);
    countries.push_back(morocco);
    countries.push_back(nepal);
    countries.push_back(puertoRico);
    countries.push_back(philippines);
    countries.push_back(russia);
    countries.push_back(saudiArabia);
    countries.push_back(serbia);
    countries.push_back(somalia);
    countries.push_back(spain);
    countries.push_back(Syria);
    countries.push_back(venezuela);
    countries.push_back(yemen);

//Tell the user to enter at least 2 ingredients 
std::cout << "Enter at least two ingredients (if an ingredient consists of two separate words, write it as one word, e.g., bellpeppers): ";
std::string userInput;//decalre a string variable that will store what the user Inputs
//getline() can be used to read an entire line of text inputted 
std::getline(std::cin, userInput); //This will allow the user to input items with spaces in between them and input will be stored in 'userInput'

std::istringstream iss(userInput);
std::vector<std::string> userIngredients;//need a vector to store the users ingredients here, it will store the ingredients that the user inputs
std::copy(
   std::istream_iterator<std::string>(iss),//will help to read strings from the stream, it creates an input iterator 
    std::istream_iterator<std::string>(),//this is the end of the iterator for the input stream
  std::back_inserter(userIngredients)//will help to insert the string to the end of the vector 
);

    std::sort(userIngredients.begin(), userIngredients.end()); //this line will organize the ingredients to be in alphabetical order

    if (userIngredients.size() < 2) { //implement an if statement which will check if the # of ingredients the user entered is less than 2
        std::cout << "Not enough ingredients to make a dish." << std::endl; //if the # inputted is less than 2 this message will be displayed 
        return 0; //this will end the program since user did not input enough 
    }

  
    /* This line will create a list called 'matchingIndices' which is a vector being declared that will keep track of the positions 
    of countries whose dishes can be made with the ingredients that are entered by the user */
    std::vector<size_t> matchingIndices;

    for (size_t i = 0; i < countries.size(); ++i) { //a for loop which will be needed to iterate over each country in the vector 'countries'
       //the loop will check using the hasIngredients function if the ingredients from the country match what was entered by user 
        if (hasIngredients(userIngredients, countries[i])) { 
            matchingIndices.push_back(i); //code will keep track of the countries position at index i by adding it to the list of matching countries 
        }
    }
        if (matchingIndices.empty()) {
            std::cout << "No matching countries" << std::endl; //will display a message if there are no countries that match the users input
        } else {
            std::cout << "Matching countries:" << std::endl; //will display a message if there are countries that match the users input 

    //Display the matching countries
    for (size_t i = 0; i < matchingIndices.size(); ++i) {
        size_t index = matchingIndices[i]; //get the index of the current matching country in the countries vector 
        std::cout << i + 1 << ". " << countries[index].name; //print the name of the countries that match users input 
        // Display dish name when there is only one matching country
        if (matchingIndices.size() == 1) {
            std::cout << " Dish: " << countries[index].dishName; //this will display "Dish" and then get the dish of that specefic country 
        }
        std::cout << std::endl; //move to the next line, to see the next country 
    }
        if (matchingIndices.size() > 1) { //check if there is more than one matching country 
            std::cout << "Choose a country (enter the number): "; //prompt the user to enter the number of the country listed 
            
        int choice; 
        if (!(std::cin >> choice)) { //check if the # the user inputted is a valid choice 
        std::cout << "Invalid input." << std::endl; //will let the user know there input is invalid but message regarding food waste will still be presented 
        return 1;
    }
    /*use if statement to verify if what the user chose 
    corresponds to a valid index in the matchingIndices*/   
    if (choice > 0 && static_cast<size_t>(choice) <= matchingIndices.size()) { 
        size_t index = matchingIndices[choice - 1]; //get the index of the chosen country in the matchingIndices vector
        const Country& chosenCountry = countries[index];
        std::cout << "You chose: " << chosenCountry.name << std::endl; //Display the country the user chose 
        std::cout << "Dish: " << chosenCountry.dishName << std::endl; //Display the dishes name of the country the user chooses 

        //Display the additional ingredients needed for the chosen dish if the user did not enter all of them 
        std::cout << "Additional ingredients needed for " << chosenCountry.dishName << ":\n";
        for (std::vector<std::string>::const_iterator it = chosenCountry.ingredients.begin(); it != chosenCountry.ingredients.end(); ++it) {
            if (std::find(userIngredients.begin(), userIngredients.end(), *it) == userIngredients.end()) {
                std::cout << "- " << *it << '\n';
            }
        }
        
        }else{
        std::cout << "Invalid choice." << std::endl;
    }
}

    // Display cooking directions message 
    std::cout << "\n\nCooking Directions:\n";
    //Inform the user to search online for the dishs cooking instructions 
    std::cout << "Follow your favorite recipe or search online for detailed cooking instructions and ingredients for this special dish!"; 

    // Display some facts about food waste
    std::cout << "\n\nDid you know?\n"
        << "-Food loss and waste contribute to approximately 4.4 gigatonnes of greenhouse gas emissions each year.\n"
        << "-Food loss can result in reduced income for farmers and lead to higher prices for consumers, creating economic incentives to minimize food waste.\n"
        << "-In 2015, the United States Department of Agriculture, along with the U.S. Environmental Protection Agency "<< 
            "set a commendable goal to decrease the country's food waste by half by the year 2030.\n";


    // Display some recommended ways to reduce food waste
    std::cout << "\nRecommended Ways To Reduce Food Waste...\n"
            << "- Create a meal plan\n"
            << "- Save and eat leftovers\n"
            << "- Use leftover ingredients creatively by exploring new dishes\n"
            << "- Convert left over food to compost\n";
    }

return 0;

} 
