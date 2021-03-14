

#include "Matrix.h"



Matrix& Matrix::operator=(const std::vector<std::vector<int>> & data)
{
	for (int i = 0; i < data.size(); ++i)
	{
		std::vector<int> row;
		for (int j = 0; j < data.size(); ++j)
		{
			row.push_back(data[i][j]) ;
		}
		this->_data.push_back(row);
	}
	return  *this;
};
Matrix& Matrix::operator+=(const Matrix & other)
{
	for (int i = 0; i < other._data.size(); ++i)
	{
		for (int j = 0; j < other._data.size(); ++j)
		{
			this->_data[i][j] += other._data[i][j];
		}

	}
	return  *this;

};
Matrix& Matrix::operator-=(const Matrix & other)
{
	for (int i = 0; i < other._data.size(); ++i)
	{
		for (int j = 0; j < other._data.size(); ++j)
		{
			this->_data[i][j] -= other._data[i][j];
		}

	}
	return  *this;
};
Matrix& Matrix::operator*=(const Matrix & other)
{
	for (int i = 0; i < other._data.size(); ++i)
	{
		for (int j = 0; j < other._data.size(); ++j)
		{
			this->_data[i][j] *= other._data[i][j];
		}

	}
	return  *this;
};
Matrix& Matrix::operator/=(const Matrix & other)
{
	for (int i = 0; i < other._data.size(); ++i)
	{
		for (int j = 0; j < other._data.size(); ++j)
		{
			if (other._data[i][j] == 0)
			{
				this->_data[i][j] = 0;
			}else
			{
				this->_data[i][j] /= other._data[i][j];
			}
		}
	}
	return  *this;
};

std::ostream& operator<<(std::ostream & os,
    const Matrix & matrix)
{
	for (int i = 0; i < matrix._data.size(); ++i)
	{
		for (int j = 0; j < matrix._data.size(); ++j)
		{
			os << matrix._data[i][j] << " ";
		}
		os << std::endl;
	}
	return os;
};