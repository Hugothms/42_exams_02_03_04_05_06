/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:10:33 by hthomas           #+#    #+#             */
/*   Updated: 2021/07/08 22:20:47 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <string>
# include <iostream>

using namespace std;

class Warlock
{
private:
	string name;
	string title;
public:
	Warlock(string const name, string const title): name(name), title(title)
	{
		cout << name << ": This looks like another boring day." << endl;
	}

	~Warlock()
	{
		cout << name << ": My job here is done!" << endl;
	}

	string const &getName() const
	{
		return name;
	}

	string const &getTitle() const
	{
		return title;
	}

	void setTitle(string const &title)
	{
		this->title = title;
	}

	void introduce() const
	{
		cout << name << ": I am " << name << ", " << title << " !" << endl;
	}
};

#endif
