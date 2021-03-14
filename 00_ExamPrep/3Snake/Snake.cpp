#include "Snake.h"

Snake::Snake(const int fieldRows, const int fieldCols, const Point& startPos) :
	_FIELD_ROWS(fieldRows), _FIELD_COLS(fieldCols), _currPos(startPos)
{
	this->_snakeNodes.push_back(startPos);
};

Snake::~Snake()
{
	this->_snakeNodes.clear();
}

StatusCode Snake::move(const Direction dir, const std::vector<Point>& obstacles, std::vector<Point>& powerUps)
{
	auto nodes = getSnakeNodes();
	if (dir == Direction::UP)
	{
		if (nodes[0].row == 0)
		{
			return StatusCode::SNAKE_DEAD;
		}
		else
		{
			for (int i = 0; i < obstacles.size(); ++i)
			{
				if (obstacles[i].row == nodes[0].row - 1 && obstacles[i].col == nodes[0].col)
				{
					return StatusCode::SNAKE_DEAD;
				}
			}
			for (int i = 0; i < nodes.size(); ++i)
			{
				if (nodes[i].row == nodes[0].row - 1 && nodes[i].col == nodes[0].col)
				{
					return StatusCode::SNAKE_DEAD;
				}
			}
			for (int i = 0; i < powerUps.size(); ++i)
			{
				if (powerUps[i].row == nodes[0].row - 1 && powerUps[i].col == nodes[0].col)
				{
					this->_snakeNodes.insert(this->_snakeNodes.begin(), *new Point(powerUps[i].row, powerUps[i].col));
					for (int j = i; j < powerUps.size() - 1; ++j)
					{
						powerUps[j] = powerUps[j + 1];
					}
					powerUps.pop_back();
					return StatusCode::SNAKE_GROWING;
				}
			}
			if (this->_snakeNodes.size() > 1)
			{
				int num = _snakeNodes[0].row - 1 ;
				_snakeNodes.insert(_snakeNodes.begin(), *new Point(num, _snakeNodes[0].col));
				_snakeNodes.pop_back();
			}
			else
			{
				_snakeNodes[0].row--;
			}
		
			return StatusCode::SNAKE_MOVING;
		}
	}
	if (dir == Direction::DOWN)
	{
		if (nodes[0].row == this->_FIELD_ROWS - 1)
		{
			return StatusCode::SNAKE_DEAD;
		}
		else
		{
			for (int i = 0; i < obstacles.size(); ++i)
			{
				if (obstacles[i].row == nodes[0].row + 1 && obstacles[i].col == nodes[0].col)
				{
					return StatusCode::SNAKE_DEAD;
				}
			}
			for (int i = 0; i < nodes.size(); ++i)
			{
				if (nodes[i].row == nodes[0].row + 1 && nodes[i].col == nodes[0].col)
				{
					return StatusCode::SNAKE_DEAD;
				}
			}
			for (int i = 0; i < powerUps.size(); ++i)
			{
				if (powerUps[i].row == nodes[0].row + 1 && powerUps[i].col == nodes[0].col)
				{
					this->_snakeNodes.insert(this->_snakeNodes.begin(), *new Point(powerUps[i].row, powerUps[i].col));
					for (int j = i; j < powerUps.size() - 1; ++j)
					{
						powerUps[j] = powerUps[j + 1];
					}
					powerUps.pop_back();
					return StatusCode::SNAKE_GROWING;
				}
			}
			if (this->_snakeNodes.size() > 1)
			{
				int num = _snakeNodes[0].row + 1;
				_snakeNodes.insert(_snakeNodes.begin(), *new Point(num, _snakeNodes[0].col ));
				_snakeNodes.pop_back();
			}else
			{
				_snakeNodes[0].row++;
			}
		
			return StatusCode::SNAKE_MOVING;
		}
	}
	if (dir == Direction::LEFT)
	{
		if (nodes[0].col == 0)
		{
			return StatusCode::SNAKE_DEAD;
		}
		else
		{
			for (int i = 0; i < obstacles.size(); ++i)
			{
				if (obstacles[i].row == nodes[0].row && obstacles[i].col == nodes[0].col - 1)
				{
					return StatusCode::SNAKE_DEAD;
				}
			}

			for (int i = 0; i < nodes.size(); ++i)
			{
				if (nodes[i].row == nodes[0].row && nodes[i].col == nodes[0].col - 1)
				{
					return StatusCode::SNAKE_DEAD;
				}
			}
			for (int i = 0; i < powerUps.size(); ++i)
			{
				if (powerUps[i].row == nodes[0].row && powerUps[i].col == nodes[0].col - 1)
				{
					this->_snakeNodes.insert(this->_snakeNodes.begin(), *new Point(powerUps[i].row, powerUps[i].col));
					for (int j = i; j < powerUps.size() - 1; ++j)
					{
						powerUps[j] = powerUps[j + 1];
					}
					powerUps.pop_back();
					return StatusCode::SNAKE_GROWING;
				}
			}
			if (this->_snakeNodes.size() > 1)
			{
				int num = _snakeNodes[0].col - 1;
				_snakeNodes.insert(_snakeNodes.begin(), *new Point(_snakeNodes[0].row, num));
				_snakeNodes.pop_back();
			}
			else
			{
				_snakeNodes[0].col--;
			}
			return StatusCode::SNAKE_MOVING;
		}
	}
	if (dir == Direction::RIGHT)
	{
		if (nodes[0].col == this->_FIELD_COLS - 1)
		{
			return StatusCode::SNAKE_DEAD;
		}
		else
		{
			for (int i = 0; i < obstacles.size(); ++i)
			{
				if (obstacles[i].row == nodes[0].row && obstacles[i].col == nodes[0].col + 1)
				{
					return StatusCode::SNAKE_DEAD;
				}
			}
			for (int i = 0; i < nodes.size(); ++i)
			{
				if (nodes[i].row == nodes[0].row && nodes[i].col == nodes[0].col + 1)
				{
					return StatusCode::SNAKE_DEAD;
				}
			}
			for (int i = 0; i < powerUps.size(); ++i)
			{
				if (powerUps[i].row == nodes[0].row && powerUps[i].col == nodes[0].col + 1)
				{
					this->_snakeNodes.insert(this->_snakeNodes.begin(), *new Point(powerUps[i].row, powerUps[i].col));
					for (int j = i; j < powerUps.size() - 1; ++j)
					{
						powerUps[j] = powerUps[j + 1];
					}
					powerUps.pop_back();
					return StatusCode::SNAKE_GROWING;
				}
			}

			if (this->_snakeNodes.size() > 1)
			{
				int num = _snakeNodes[0].col + 1;
				_snakeNodes.insert(_snakeNodes.begin(), *new Point(_snakeNodes[0].row, num));
				_snakeNodes.pop_back();
			}
			else
			{
				_snakeNodes[0].col++;
			}

			return StatusCode::SNAKE_MOVING;
		}
	}

	return StatusCode::STATUS_UNKNOWN;
};

std::deque<Point>& Snake::getSnakeNodes()
{
	return this->_snakeNodes;
};