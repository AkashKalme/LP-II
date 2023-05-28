symptoms = ["Cold", "Cough", "Fever", "Headache", "Sore Throat"]

diseases = {
    "Common Cold": ["Cold", "Cough", "Fever", "Headache", "Sore Throat"],
    "Flu": ["Cough", "Fever", "Headache"],
    "Migrane": ["Headache"],
}


def getUserInput():
    userSymptoms = []
    for symptom in symptoms:
        response = input(f"Do you have {symptom}? (y/n)")
        if (response.lower() == 'y'):
            userSymptoms.append(symptom)
    return userSymptoms


def diagonse():
    userSymptoms = getUserInput()
    possibleDiseases = []

    for disease, symptoms in diseases.items():
        if all(symptom in userSymptoms for symptom in symptoms):
            possibleDiseases.append(disease)

    if (possibleDiseases):
        print("You may be suffring from: ")
        for disease in possibleDiseases:
            print(disease)
    else:
        print("Sorry! We couldn't diagonse your disease.")


if __name__ == "__main__":
    diagonse()
