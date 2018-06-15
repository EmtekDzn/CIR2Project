-- phpMyAdmin SQL Dump
-- version 4.5.4.1deb2ubuntu2
-- http://www.phpmyadmin.net
--
-- Client :  localhost
-- Généré le :  Ven 15 Juin 2018 à 11:13
-- Version du serveur :  5.7.22-0ubuntu0.16.04.1
-- Version de PHP :  7.0.30-0ubuntu0.16.04.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `testabc`
--

-- --------------------------------------------------------

--
-- Structure de la table `Partie`
--

CREATE TABLE `Partie` (
  `id_partie` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Structure de la table `Partie_Question`
--

CREATE TABLE `Partie_Question` (
  `id_question` int(11) NOT NULL,
  `id_partie` int(11) NOT NULL,
  `id_proposition` int(32) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Structure de la table `Partie_User`
--

CREATE TABLE `Partie_User` (
  `id_partie` int(11) NOT NULL,
  `id_user` int(11) NOT NULL,
  `score` int(11) NOT NULL,
  `id_partie_user` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Structure de la table `Proposition`
--

CREATE TABLE `Proposition` (
  `id_proposition` int(11) NOT NULL,
  `proposition` varchar(50) NOT NULL,
  `bonne_reponse` int(11) NOT NULL,
  `id_question` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Contenu de la table `Proposition`
--

INSERT INTO `Proposition` (`id_proposition`, `proposition`, `bonne_reponse`, `id_question`) VALUES
(1, 'Elle est blonde', 1, 1),
(2, 'Elle est cotée à l\'Argus', 2, 1),
(3, 'Elle ne coute pas cher', 3, 1),
(4, 'Elle n\'a pas que des pieces d\'origine', 3, 1),
(5, 'Elle passe de main en main', 3, 1),
(6, 'On peut l\'acheter à un ami', 2, 1),
(7, 'Elle a des kilometres au compteur', 3, 1),
(8, 'A fait du cinéma', 3, 2),
(9, 'Peut changer de forme', 2, 2),
(10, 'Est né(e) en 1976', 1, 2),
(11, 'Est poilu(e)', 2, 2),
(12, 'A son propre fan-club', 3, 2),
(13, 'A un fabuleux destin', 3, 2),
(14, 'Ne sait dire que son nom', 2, 2),
(15, 'Il faut se serrer la main avant', 1, 3),
(16, 'Ça arrive souvent après une dégustation de cassoul', 2, 3),
(17, 'Tout comme les enfants on supporte mieux le sien q', 2, 3),
(18, 'On peut regretter amèrement de l\'avoir fait', 3, 3),
(19, 'Ça peut soulager une nation entière', 3, 3),
(20, 'Gainsbourg en a fait un livre', 2, 3),
(21, 'Ca peut engendrer des conflits', 2, 3),
(22, 'Il ne chante pas', 2, 4),
(23, 'Il n\'y a aucune raison de le ficeler', 1, 4),
(24, 'Il s\'exprime comme ça "ahhhhhhhhhhhhhhhhhhhhh"', 1, 4),
(25, 'Il a des bonnes cuisses', 1, 4),
(26, 'Il est chargé de cholestérol', 3, 4),
(27, 'Tu peux en avoir la moitié si tu veux', 1, 4),
(29, 'Impératrice', 1, 5),
(30, 'Vit dans un monde merveilleux', 3, 5),
(31, 'A vraiment existé', 1, 5),
(32, 'Est marié(e)', 1, 5),
(33, 'Potiron', 2, 5),
(34, 'Romy Schneider', 1, 5),
(35, 'Vous fait perdre à ni oui, ni non', 3, 5),
(36, 'Joue au foot', 1, 6),
(37, 'A une fermeture éclair sur la gueule', 2, 6),
(38, 'A le crâne rasé', 1, 6),
(39, 'C\'est pas un beau gosse', 3, 6),
(40, 'Est champion du monde', 1, 6),
(41, 'A fait du cinéma', 3, 6),
(42, 'Son corps est fait à partir de différents cadavres', 2, 6),
(43, 'Il est petit', 3, 7),
(44, 'Médaille d\'or', 1, 7),
(45, 'Fait rire les enfants', 2, 7),
(46, 'A fait fort Boyard', 1, 7),
(47, 'Sort tout droit d\'un Walt Disney', 2, 7),
(48, 'Nique l\'autre à la bagarre', 3, 7),
(49, 'Éternue', 3, 7),
(50, 'On peut taper dessus', 3, 8),
(51, 'Maire de Neuilly', 1, 8),
(52, 'Il a une tête plate', 3, 8),
(53, 'Il vaut mieux éviter de marcher dessus', 2, 2),
(54, 'Il a le bout pointu', 2, 8),
(55, 'Il en existe sans tête', 2, 8),
(57, 'Il est très utile', 2, 8),
(58, 'Il est apparu à Bayonne', 1, 9),
(59, 'Il sent le fromage à certaines heures', 3, 9),
(60, 'A la patte molle', 3, 9),
(61, 'Il est bon, il est crémeux', 2, 9),
(62, 'Il est surnommé Blanchart', 1, 9),
(63, 'Il n\'a jamais marqué en équipe de france', 2, 9),
(71, 'Au moins 20 millions d\'exemplaires vendus', 3, 23),
(72, 'Français', 3, 23),
(73, 'Tousse au démarrage', 3, 23),
(75, 'Il est musicien', 2, 24),
(76, 'D\'origine russe', 2, 24),
(77, 'Diplômé du conservatoire de Moscou', 2, 24),
(78, 'Il est bien garnis', 1, 25),
(79, 'Il part du nord ouest pour aller au sud est', 2, 25),
(80, 'Il faut l\'entretenir', 2, 25),
(81, 'Il adore manger', 3, 26),
(82, 'Il a un gros menhir', 2, 26),
(83, 'On l\'appelle Petard', 2, 26),
(85, 'Elu BDE', 1, 28),
(86, 'A voté pour l\'équipe adverse', 1, 28),
(87, 'Nous ont rasé le crane', 3, 28),
(88, 'Ils ont des meilleures notes en physique', 2, 29),
(89, 'Ils sont fetards', 2, 29),
(90, 'Ils sont vraiment fetards', 1, 29);

-- --------------------------------------------------------

--
-- Structure de la table `Question`
--

CREATE TABLE `Question` (
  `id_question` int(11) NOT NULL,
  `question` varchar(50) NOT NULL,
  `id_categorie` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Contenu de la table `Question`
--

INSERT INTO `Question` (`id_question`, `question`, `id_categorie`) VALUES
(1, 'Pamela Anderson,Une voiture d\'occasion,Les deux ', 7),
(2, 'Audrey Tautou,Pikachu,Les deux ?', 3),
(3, 'La paix,Un pet,Les deux ?', 8),
(4, 'Pavarotti,Poulet rôti,Les deux ?', 9),
(5, 'Sissi,Oui-Oui,Les deux ?', 5),
(6, 'Franck Leboeuf,Frankenstein,Les deux ?', 10),
(7, 'Brahim Asloum,Atchoum,Les deux ?', 10),
(8, 'Nicolas Sarkozy,Un clou,Les deux ?', 2),
(9, 'Didier Deschamps,La belle des champs,Les deux ?', 10),
(23, 'Renaud,Renault,Les deux ?', 9),
(24, 'Serge Gainsbourg,Anton Ginsburg,Les deux ?', 9),
(25, 'Jean Dujardin,Mon jardin,Les deux ?', 3),
(26, 'Gérard Depardieu,Obelix,Les deux?', 3),
(28, 'Cosmunity,Pixel,Les Deux ?', 18),
(29, 'CIR,BIOST,Les deux ?', 18);

-- --------------------------------------------------------

--
-- Structure de la table `Theme`
--

CREATE TABLE `Theme` (
  `id_categorie` int(11) NOT NULL,
  `categorie` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Contenu de la table `Theme`
--

INSERT INTO `Theme` (`id_categorie`, `categorie`) VALUES
(2, 'Politique'),
(3, 'Cinema'),
(5, 'Culture'),
(7, 'People'),
(8, 'Divers'),
(9, 'Art'),
(10, 'Sport'),
(18, 'Isen');

-- --------------------------------------------------------

--
-- Structure de la table `User`
--

CREATE TABLE `User` (
  `id_user` int(11) NOT NULL,
  `username` varchar(50) NOT NULL,
  `password` varchar(50) NOT NULL,
  `admin` tinyint(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Contenu de la table `User`
--

INSERT INTO `User` (`id_user`, `username`, `password`, `admin`) VALUES
(1, 'admin', '21232f297a57a5a743894a0e4a801fc3', 1);

--
-- Index pour les tables exportées
--

--
-- Index pour la table `Partie`
--
ALTER TABLE `Partie`
  ADD PRIMARY KEY (`id_partie`);

--
-- Index pour la table `Partie_Question`
--
ALTER TABLE `Partie_Question`
  ADD PRIMARY KEY (`id_question`,`id_partie`,`id_proposition`),
  ADD KEY `Partie_Question_Partie0_FK` (`id_partie`),
  ADD KEY `azerty` (`id_proposition`);

--
-- Index pour la table `Partie_User`
--
ALTER TABLE `Partie_User`
  ADD PRIMARY KEY (`id_partie_user`),
  ADD KEY `Partie_User_User0_FK` (`id_user`);

--
-- Index pour la table `Proposition`
--
ALTER TABLE `Proposition`
  ADD PRIMARY KEY (`id_proposition`),
  ADD KEY `Proposition_Question_FK` (`id_question`);

--
-- Index pour la table `Question`
--
ALTER TABLE `Question`
  ADD PRIMARY KEY (`id_question`),
  ADD KEY `Question_Theme_FK` (`id_categorie`);

--
-- Index pour la table `Theme`
--
ALTER TABLE `Theme`
  ADD PRIMARY KEY (`id_categorie`);

--
-- Index pour la table `User`
--
ALTER TABLE `User`
  ADD PRIMARY KEY (`id_user`);

--
-- AUTO_INCREMENT pour les tables exportées
--

--
-- AUTO_INCREMENT pour la table `Partie`
--
ALTER TABLE `Partie`
  MODIFY `id_partie` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `Partie_User`
--
ALTER TABLE `Partie_User`
  MODIFY `id_partie_user` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `Proposition`
--
ALTER TABLE `Proposition`
  MODIFY `id_proposition` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=93;
--
-- AUTO_INCREMENT pour la table `Question`
--
ALTER TABLE `Question`
  MODIFY `id_question` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=32;
--
-- AUTO_INCREMENT pour la table `Theme`
--
ALTER TABLE `Theme`
  MODIFY `id_categorie` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=20;
--
-- AUTO_INCREMENT pour la table `User`
--
ALTER TABLE `User`
  MODIFY `id_user` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=27;
--
-- Contraintes pour les tables exportées
--

--
-- Contraintes pour la table `Partie_Question`
--
ALTER TABLE `Partie_Question`
  ADD CONSTRAINT `Partie_Question_Partie0_FK` FOREIGN KEY (`id_partie`) REFERENCES `Partie` (`id_partie`),
  ADD CONSTRAINT `Partie_Question_Question_FK` FOREIGN KEY (`id_question`) REFERENCES `Question` (`id_question`),
  ADD CONSTRAINT `azerty` FOREIGN KEY (`id_proposition`) REFERENCES `Proposition` (`id_proposition`);

--
-- Contraintes pour la table `Proposition`
--
ALTER TABLE `Proposition`
  ADD CONSTRAINT `Proposition_Question_FK` FOREIGN KEY (`id_question`) REFERENCES `Question` (`id_question`);

--
-- Contraintes pour la table `Question`
--
ALTER TABLE `Question`
  ADD CONSTRAINT `Question_Theme_FK` FOREIGN KEY (`id_categorie`) REFERENCES `Theme` (`id_categorie`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
