#ifndef __OBJECT_H__
#define __OBJECT_H__

class object
{
    public:
        /**
        * @brief Construct a new object object
        * 
        * @param solidity le point de solidité de l'objet crée
        */
        object(int solidity);

        /**
         * @brief Renvoie le solidité de l'objet
         * 
         * @return int 
         */
        int solidity() const;

        /**
         * @brief Reduit le point de solidité d'un objet
         * 
         * @pre nb > 0
         * @param nb nombre de reduction
         */
        void reduce(int nb);

        /**
         * @brief Augmente le point de solidité d'un objet
         * 
         * @pre nb > 0
         * @param nb nombre d'augmentation
         */
        void increase(int nb);
    private:
        // point de solidité
        int d_solidity;
};

#endif