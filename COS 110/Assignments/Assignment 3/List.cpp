template <class T>
List<T>::~List() // Function 1
{}

template <class T>
std::ostream& operator<<(std::ostream& out, const List<T>& list) // Function 8
{
    return list.print(out);
}

template <class T>
template <class U> ////////////////////////// Might have to remove this and change the below const "U" to cont "T"
bool List<T>::operator==(const U& rhs) const // Function 9
{

    int currObjectSize = int(*this);

    if (currObjectSize == int(rhs))
    {
       for (int i = 0; i < currObjectSize; i++)
        {
            try
            {
                if ((*this)[i] != rhs[i])
                    return false;
            }catch (InvalidIndexException&)
            {
                return false;
            }
        }

        return true;
    }

    return false;
}
