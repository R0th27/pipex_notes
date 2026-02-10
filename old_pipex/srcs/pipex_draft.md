void	create_child(t_cmd *cmd, char **envp)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
		exec_cmd(cmd, envp);
	else
	{
		waitpid(pid, &status, 0);
		printf("status: %d\n", status >> 8);
	}
}

void	file_test(int ac, char **av)
{
	t_input_type	type;
	int				infile;
	int				outfile;

	type = INPUT_FILE;
	infile = setup_input_fd(type, av[1]);
	outfile = setup_output_fd(type, av[ac - 1]);
	printf("infile %d\n", infile);
	printf("outfile %d\n", outfile);
}
