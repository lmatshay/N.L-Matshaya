/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 11:23:23 by lmatshay          #+#    #+#             */
/*   Updated: 2016/08/26 11:37:44 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

static	void	sig_usr(int signo)
{
	if (signo == SIGABRT)
		printf("received SIGUSR1\n");
	else if (signo == SIGUSR2)
		printf("received SIGUSR2\n");
	else
		printf("received signal %d\n", signo);
}

int				main(void)
{
	if (signal(SIGUSR1, sig_usr) == SIG_ERR)
		printf("cant catch SIGUSR1\n");
	if (signal(SIGUSR2, sig_usr) == SIG_ERR)
		printf("cant catch SIGUSR2\n");
	while (42)
		pause();
}
