/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poubelle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:09:57 by svanmeen          #+#    #+#             */
/*   Updated: 2023/08/28 20:09:59 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	charset(t_map map)
{
	if (map.val == ' ')
		return (1);
	return (0);
}

int	border(int i, t_settings *set, int old)
{
	if (i < 0 || i > set->map_heigh * set->map_width)
		return (0);
	if (ft_abs(old - i) != set->map_width)
		return (0);
	return (1);
}

/*
int	go_first(t_map *map, int i, t_settings *set, int old, int *k)
{
	if (old - i == -1 && border(map, i - set->map_width, set, i))
		return (track(map, i - set->map_width, set, i, k));
	else if (old - i == 1 && border(map, i + set->map_width, set, i))
		return (track(map, i + set->map_width, set, i, k));
	else if (old - i == -set->map_width && border(map, i + 1, set, i))
		return (track(map, i + 1, set, i, k));
	else if (old - i == set->map_width && border(map, i - 1, set, i))
		return (track(map, i - 1, set, i, k));
	return (1);
}

int	go_front(t_map *map, int i, t_settings *set, int old, int *k)
{
	if (old - i == -1 && border(map, i + 1, set, i))
		return (track(map, i + 1, set, i, k));
	else if (old - i == 1 && border(map, i - 1, set, i))
		return (track(map, i - 1, set, i, k));
	else if (old - i == -set->map_width && border(map, i + set->map_width, set, i))
		return (track(map, i + set->map_width, set, i, k));
	else if (old - i == set->map_width && border(map, i - set->map_width, set, i))
		return (track(map, i - set->map_width, set, i, k));
	return (1);
}

int	go_follow(t_map *map, int i, t_settings *set, int old, int *k)
{
	if (old - i == -1 && border(map, i + set->map_width, set, i))
		return (track(map, i + set->map_width, set, i, k));
	else if (old - i == 1 && border(map, i - set->map_width, set, i))
		return (track(map, i + set->map_width, set, i, k));
	else if (old - i == -set->map_width && border(map, i - 1, set, i))
		return (track(map, i - 1, set, i, k));
	else if (old - i == set->map_width && border(map, i - 1, set, i))
		return (track(map, i - 1, set, i, k));
	return (1);
}

int	go_second(t_map *map, int i, t_settings *set, int old, int *k)
{
	if (old - i == -1 && border(map, i + 1, set, i))
		return (track(map, i + 1, set, i, k));
	else if (old - i == 1 && border(map, i - 1, set, i))
		return (track(map, i - 1, set, i, k));
	else if (old - i == -set->map_width \
		&& border(map, i + set->map_width, set, i))
		return (track(map, i + set->map_width, set, i, k));
	else if (old - i == set->map_width \
		&& border(map, i - set->map_width, set, i))
		return (track(map, i - set->map_width, set, i, k));
	return (1);
}

int	go_third(t_map *map, int i, t_settings *set, int old, int *k)
{
	if (old - i == -1 && border(map, i + set->map_width, set, i))
		return (track(map, i + set->map_width, set, i, k));
	else if (old - i == 1 && border(map, i - set->map_width, set, i))
		return (track(map, i - set->map_width, set, i, k));
	else if (old - i == -set->map_width && border(map, i - 1, set, i))
		return (track(map, i - 1, set, i, k));
	else if (old - i == set->map_width && border(map, i + 1, set, i))
		return (track(map, i + 1, set, i, k));
	return (1);
}

int	track(t_map *map, int i, t_settings *set, int old, int *k)
{
	int	ways;

	map[i].val = 1;
	ways = get_nb_wall(map, i, set);
	ft_printf("map[%d].val = %d x: %d y: %d\n", i, map[i].val, map[i].x, map[i].y);
	if (ways == 0 && i == set->origin)
	{
		*k = 0;
		return (0);
	}
	else if (ways > 0 && *k == 1)
	{
		if (go_front(map, i, set, old, k) && *k == 1)
		{
			if (go_follow(map, i, set, old, k) && *k == 1)
			{
				//if (go_third(map, i, set, old, k) && *k == 1)
					//return (*k);
			}
		}
		else
			return (*k);
	}
	return (*k);
}
*/
/*
int	get_nb_wall(t_map *map, int i, t_settings *set)
{
	int	nb_ways;

	nb_ways = 0;
	if (border(map, i - 1, set, i) && map[i - 1].val == 49)
		nb_ways++;
	if (border(map, i + 1, set, i) && map[i + 1].val == 49)
		nb_ways++;
	if (border(map, i - set->map_width, set, i) \
		&& map[i - set->map_width].val == 49)
		nb_ways++;
	if (border(map, i + set->map_width, set, i) \
		&& map[i + set->map_width].val == 49)
		nb_ways++;
	return (nb_ways);
}

int	get_next(t_map *map, int i, t_settings *set, int from)
{
	if (border(map, i + 1, set, from) && map[i + 1].val == 49 && i + 1 != from)
		return (i + 1);
	if (border(map, i - 1, set, from) && map[i - 1].val == 49 && i - 1 != from)
		return (i - 1);
	if (border(map, i + set->map_width, set, from) \
		&& map[i + set->map_width].val == 49 && i + set->map_width != from)
		return (i + set->map_width);
	if (border(map, i - set->map_width, set, from) \
		&& map[i - set->map_width].val == 49 && i - set->map_width != from)
		return (i - set->map_width);
	return (0);
}

int	backtrack(t_settings *set, t_map *map)
{
	int		i;
	int		k;

	i = 0;
	k = 1;
	if (map[i].val != 49)
	{
		while (charset(map[i]))
			i += 1;
	}
	set->origin = i;
	if (track(map, i + 1, set, i, &k))
		return (EXIT_FAILURE);
	return (0);
}*/
