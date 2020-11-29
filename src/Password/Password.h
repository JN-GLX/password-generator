/*!
 * \file Password.h
 * \brief Générateur de mot de passe prononçable
 * \author jn-glx
 * \date 21 nov. 2020
 * \version 0.1
 *
 */

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#ifndef SRC_PASSWORD_H_
#define SRC_PASSWORD_H_

/*! \class Password Password.h "Définition".
 * \brief Classe représentant le mot de passe.
 *
 * La classe gère la génération d'un mot de passe
 *
 */
class Password
{
public:
    /*!
     * \brief Constructeur
     *
     * Constructeur de la classe Password
     *
     */
    Password();
    /*!
     * \brief Destructeur
     *
     * Destructeur de la classe Password;
     */
    virtual ~Password();

    /*!
     *
     * \brief Création d'un mot de passe prononçable
     *
     * Méthode qui permet la création d'un mot de passe
     * prononçable de 9 caractères composé ainsi:
     * - 2 séquences consonne-voyelle-consonne
     * - 1 chiffre
     * - 2 caractères spéciaux (.,?;:!_-()[]={}#+&*%@$<>)
     *
     * A partir de la fonction PHP créée par Andreas Gohr et
     * adaptée par Yannick Sebastia
     *
     * \return mot de passe prononçable
     */
    static std::string createBasePwd();

    /*!
     * \brief Génération d'un mot de passe d'une longueur donnée.
     *
     * Méthode pour générer un mot de passe supérieur à 9 caractères.
     *
     * \param length : longueur du mot de passe
     * \return mot de passe prononçable de longueur *length*
     */
    std::string generatePwd(int length);

public:
    /*! Longueur minimale du mot de passe */
    static const int MIN_LENGTH_PWD = 9;

private:
    /*! Listes de caractères pour le générateur */
    static constexpr const char* CONSONANTS = "bcdfghjklmnpqrstvwzx";
    static constexpr const char* UPPER_CONSONANTS = "BCDFGHJKLMNPQRSTVWZX";
    static constexpr const char* VOWELS = "aeiouy";
    static constexpr const char* UPPER_VOWELS = "AEIOUY";
    static constexpr const char* PUNCTUATION = ".,?;:!_-";
    static constexpr const char* SPECIALS = "()[]={}#+&*%@$<>";
};

#endif /* SRC_PASSWORD_H_ */
